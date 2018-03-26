<?php


// To create web form

function md_task($form, &$form_state) {
  $form = array();

  $form['home'] = array(
    '#type' => 'fieldset',
    '#title' => t('Enter your presonal Details'),
  );

  $form['home']['first_name'] = array(
  '#type' => 'textfield',
  '#title' => t('First Name'),
  );

  $form['home']['last_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Last Name'),
  );

  $form['home']['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email ID'),
  );

  $form['home']['closing_date'] = array(
    '#type' => 'date',
    '#title' => t('Date of Birth'),
    '#description' => t('Please chose your date of birth for submitting applications.'),
    '#default_value' => array(
    'day' => format_date(time(), 'custom', 'j'),
    'month' => format_date(time(), 'custom', 'n'),
    'year' => format_date(time(), 'custom', 'Y')),
  );

  $form['home']['selectbox'] = array(
    '#type' => 'select',
    '#title' => t('Gender'),
    '#options' => array(
    'male' => 'Male',
    'female' => 'Female',
    ),
    '#description' => t('Choose an option.'),
  );

  $form['home']['choice'] = array(
    '#type' => 'radios',
    '#title' => t('Marital Status'),
    '#description' => t('Specify your marital status.'),
    '#options' => array(
    'single' => t('Single'),
    'married' => t('Married'),
  )
  );

  $form['home']['password'] = array(
    '#type' => 'password',
    '#title' => t('Password'),
    '#description' => t('Please do not use dg as password.'),
  );

  $form['home']['save'] = array(
    '#type' => 'submit',
    '#value' =>  'Save',
  );

  return $form;

}

  // To validate web form

  function md_task_validate($form, &$form_state) {
  // Any form validation goes here like ensuring we have only alpha characters
    if ($form_state['values']['first_name'] == '') {
    form_set_error('first_name', t('Your first-name is missing, Please enter your First Name'));
  }

    if ($form_state['values']['last_name'] == '') {
    form_set_error('last_name', t('Your last-name is missing, Please enter your Last Name'));
  }

    if ($form_state['values']['email'] && !valid_email_address($form_state['values']['email'])) {
    form_set_error('email', t('The e-mail address you specified is not valid. Please enter valid e-mail address.'));
  }

    if ($form_state['values']['password'] == 'dg') {
    form_set_error('password', t('Please chose another  Password ..!'));
  }

}

  // To submit a=form data into db table

function md_task_submit($form, &$form_state) {

  // To convert date into Unixtime stamp
  global $user; // To define user variable.
$timezone = $user->timezone;  // To define user time zone..
$dateFrom = $form_state['values']['closing_date'];
$submittedFrom = "{$dateFrom['year']}-{$dateFrom['month']}-{$dateFrom['day']}";
$newFrom = new DateTime($submittedFrom, new DateTimeZone($timezone));
$unixtsFrom = $newFrom->getTimestamp();

  // Here is where you use the insert the data into your table
  db_insert('md_task')
    ->fields(array(
      'f_name' => $form_state['values']['first_name'],
      'l_name' => $form_state['values']['last_name'],
       'email' => $form_state['values']['email'],
      'b_date' => $unixtsFrom,
      'gender' => $form_state['values']['selectbox'],
      'marital_state' => $form_state['values']['choice'],
      'password' => $form_state['values']['password'],

    ))
    ->execute();
    drupal_set_message(t('Your form has saved.'));

}
