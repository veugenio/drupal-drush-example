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
      array('batch_example_1_operation_1', array())
    )
  );
  batch_set($batch);
  batch_process('batch-example');
}

function batch_example_1_operation_1() {
  sleep(2);
}