<?php
/**
 * @file
 * Admin configuration page for bulk media upload
 *
 */

/**
 * Admin configuration page
 */
function bulk_media_upload_meta_admin($form, &$form_state) {

  $form['bulk_media_upload_meta_setting'] = array(
    '#type' => 'textfield',
    '#title' => t('Field Prefixs'),
    '#default_value' => variable_get('bulk_media_upload_meta_setting', ''),
    '#size' => 32,
    '#maxlength' => 64,
    '#description' => t('(Possible Values: PREFIX_ tags, date_created, photographer, credit_byline, city, state, country, source'),
    '#required' => TRUE,
  );

  $form['bulk_media_upload_meta_document'] = array(
    '#type' => 'textfield',
    '#title' => t('Path to Meta Document'),
    '#default_value' => variable_get('bulk_media_upload_meta_document', ''),
    '#size' => 32,
    '#maxlength' => 255,
    '#description' => t('(Possible Values: /var/aegir/platforms/core/sites/bob.dev/files/meta.csv'),
    '#required' => FALSE,
  );


	$form['buttons']['scan_files'] = array(
	'#type' => 'submit',
	'#value' => t('Scan All'),
	'#weight' => 20,
	'#prefix' => '<br /><br />',
	'#submit' => array('bulk_media_upload_meta_node_scan_all_submit'),
	);

	$form['buttons']['scan_new'] = array(
	'#type' => 'submit',
	'#value' => t('Scan New'),
	'#weight' => 10,
	'#prefix' => '<br /><br />',
	'#submit' => array('bulk_media_upload_meta_node_scan_new_submit'),
	);

	$form['buttons']['scan_file'] = array(
	'#type' => 'submit',
	'#value' => t('Scan File'),
	'#weight' => 10,
	'#prefix' => '<br /><br />',
	'#submit' => array('bulk_media_upload_meta_node_scan_file_submit'),
	);
  return system_settings_form($form);
}

/**
 * Wrapper function for Scan All 
 */
function bulk_media_upload_meta_node_scan_all_submit() {
  bulk_media_upload_meta_node_scan_all(true);
}


/**
 * Wrapper function for Scan New 
 */
function bulk_media_upload_meta_node_scan_new_submit() {
  bulk_media_upload_meta_node_scan_all();
}


/**
 * Wrapper function for Scan New 
 */
function bulk_media_upload_meta_node_scan_file_submit() {
  bulk_media_upload_meta_node_scan_file();
}

?>