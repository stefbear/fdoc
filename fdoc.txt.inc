<?php

 /**
   * @file
   * Library containing functions to parse txt files.
   *   
   */

/**
 * 
 * @ingroup fdoc
 *
 * Parse txt file
 *
 */
function parse($file) {
  $realpath = drupal_realpath($file->uri);
  $fh = fopen($realpath, 'r');
  $rs = '';
  
  while(($row = fgets($fh)) !== FALSE){
    $rs .= $row;  
  }
  fclose($fh);
  return $rs;
}
