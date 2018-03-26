<?php
  function form_view_submissions() {
    $results = db_query("SELECT * FROM {md_task}");
    // this table  title fields titles
    $header = array(t('User id'), t('F Name'), t('L Name'), ('Email'), ('Date of Birth'), ('Password'), ('Gender'), ('Marital State'));
    $row = array();

    foreach($results AS $result) {
      // print('<pre>'.print_r($result,1).'</pre>');
      $rows[] = array(
        $result->user_id,
        $result->f_name,
        $result->l_name,
        $result->email,
       $dob = gmdate("m-d-Y", $result->b_date), // to convert unixtime stamp into readable date
        $result->password,
        $result->gender,
        $result->marital_state,
      );
    }

    return theme('table', array('header' => $header, 'rows' => $rows));
  }

