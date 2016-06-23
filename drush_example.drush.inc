<?php

/**
 * @file
 * Drush example module.
 */

/**
 * Implements hook_drush_command().
 */
function drush_example_drush_command() {

  // Simplest implementation.
  $items['example-1'] = array();

  // Detailed implementation.
  $items['example-2'] = array(
    'description' => dt('Text with translations.'),
  );
  
  // Batch.
  $items['example-batch'] = array(
    'description' => dt('Run batch.'),
  );

  // Batch.
  $items['example-3'] = array(
    'description' => 'Drush com argumentos.',
    'arguments' => array(
      'argumento' => 'Um argumento exemplo.'
    ),
    'callback' => 'drush_example_3',
    'examples' => array(
      'drush example-3 teste' => 'Exibe o texto "teste"',
      'drush example-3 "mais um teste"' => 'Exibe o texto "teste"',
      'drush etres teste' => 'Exibe o texto "teste"',
    ),
    'required-arguments' => 1,
    'aliases' => array('etres'),
    'options' => array(
      'nada' => array(
         'description' => 'Opção exemplo',
      ),
    )
  );

  return $items;
}

/**
 * Simplest implementation.
 */
function drush_drush_example_example_1() {
  drush_print('Example 1');
}

/**
 * Detailed implementation.
 */
function drush_drush_example_example_2() {
  $placeholder = array('!placeholder' => 'Another text');
  drush_print(dt('Example with translations: !placeholder', $placeholder));
}

/**
 * Batch over drush.
 */
function drush_drush_example_example_batch() {
  $batch = array(
    'operations' => array(
      array('drush_example_batch_operation', array())
    )
  );
  batch_set($batch);

  // Start backend process.
  drush_backend_batch_process();
}

/**
 * Drush operation.
 */
function drush_example_batch_operation($context) {
  $context['message'] = t('Message example');
  sleep(1);
}

/**
 * Command with params.
 */
function drush_example_3($argumento) {
  drush_print($argumento);
  
  $option = drush_get_option('nada', 0);
  if ($option) {
    drush_print('Nada, nada, nada... nada.');
  }
}