<?php
  function form_view_submissions() {
    $results = db_query("SELECT * FROM {md_task}");

    $header = array(t('user id'), t('f name'), t('l name'), ('email'), ('b date'), ('password'));
    $row = array();

    foreach($results AS $result) {
      // print('<pre>'.print_r($result,1).'</pre>');
      $rows[] = array(
        $result->user_id,
        $result->f_name,
        $result->l_name,
        $result->email,
        $result->b_date,
        $result->password,
      );
    }

    return theme('table', array('header' => $header, 'rows' => $rows));
  }

