<?php

/**
 * Simplest batch implementation.
 */

/**
 * Menu callback.
 */
function batch_example_1() {
  $batch = array(
    'operations' => array(
      array('batch_example_1_operation_1', array()),
      array('batch_example_1_operation_2', array()),
      array('batch_example_1_operation_3', array())
    ),
    'file' => drupal_get_path('module', 'batch_example') . '/inc/batch_example_1_1.inc'
  );
  batch_set($batch);
  batch_process('batch-example');
}

function batch_example_1_operation_1() {
  sleep(2);
}

function batch_example_1_operation_2() {
  sleep(2);
}

function batch_example_1_operation_3() {
  sleep(2);
}