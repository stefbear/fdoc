<?php

 /**
   * @file
   * Library containing functions to parse csv files.
   *   
   */

/**
 * 
 * @ingroup fdoc
 *
 * Parse csv file
 *
 */
function parse($file) {
  $realpath = drupal_realpath($file->uri);
  $fh = fopen($realpath, 'r');
  
  $table_header = NULL;
  $table = array();
  while(($row = fgetcsv($fh, NULL,';')) !== FALSE){
    if($table_header == NULL) {
      foreach($row as $field) {
        $table_header[] = $field;
      };
      continue;
    };
    $table_row = array();
    for($i = 0; $i < count($table_header) ; $i++) {
      $table_row[$table_header[$i]] = $row[$i];
    };
    $table[] = $table_row;
  }
  fclose($fh);
  
  //drupal_set_message("<pre>".print_r($table, TRUE)."</pre>");
  return print_r($table, TRUE);
}
