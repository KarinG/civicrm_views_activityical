<?php

/**
 * @file
 * Definition of civicrm_views_activityical_handler_field_link.
 */

/**
 * Description of what my handler does.
 */
class civicrm_views_activityical_handler_field_link extends views_handler_field {

  /**
   * Add some required fields needed on render().
   */
  function construct() {
    parent::construct();
    $this->additional_fields['contact_id'] = 'contact_id';
    $this->additional_fields['hash'] = 'hash';
  }

  /**
   * Loads additional fields.
   */
  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  /**
   * Default options form.
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['link_text'] = [ 'default' => 'iCalendar link' ];

    return $options;
  }

  /**
   * Creates the form item for the options added.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['link_text'] = array(
      '#type' => 'textfield',
      '#title' => t('Link text'),
      '#default_value' => $this->options['link_text'],
      '#description' => t('Link text for the calendar link.'),
      '#weight' => -10,
    );
  }

  /**
   * Renders the field.
   */
  function render($values) {
	  $render = [];

    $id = $this->get_value($values, 'contact_id');
    $hash = $this->get_value($values, 'hash');

    $link = l($this->options['link_text'], 'civicrm/activityical/feed', [
      'absolute' => TRUE,
      'query' => [
        'cid' => $this->sanitize_value($id),
        'key' => $this->sanitize_value($hash),
      ],
      'attributes' => [
        'class' => [ 'civicrm-views-activityical-link' ],
      ],
    ]);

    $link = preg_replace('#(?<=href=")https?#', 'webcal', $link);

		$render['#markup'] = $link;

    return $render;
  }
}
