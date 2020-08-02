<?php

/**
 * @file
 * Views definitions for civicrm_views_activityical module.
 */

/**
 * Implements hook_views_data().
 */
function civicrm_views_activityical_views_data() {
  $data = [];

	// Tell views about the 'civicrm_activityicalcontact' table --
	// which is part of the Activity iCal CiviCRM extension.
  $data['civicrm_activityicalcontact'] = [

    'table' => [
      'group' => t('CiviCRM Activity iCalendar'),
      'join' => [
        'civicrm_contact' => [
          'left_field' => 'id',
          'field' => 'contact_id',
	      ],
      ],
    ],

		// Faux field to render an iCalendar link.
    'civicrm_activityicalcontact_link' => [
			'real field' => 'hash',
      'title' => t('iCalendar link'),
      'help' => t('iCalendar link for contact activities.'),
      'field' => [
        'handler' => 'civicrm_views_activityical_handler_field_link',
        'click sortable' => FALSE,
      ],
    ],

  ];

  return $data;
}
