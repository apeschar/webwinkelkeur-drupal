<?php

function webwinkelkeur_invites_settings() {
    $form = array();

    $form['invites'] = array(
        '#type' => 'fieldset',
        '#title' => t('Invitations'),
    );
    $form['invites']['invites_completed_only'] = array(
        '#type' => 'checkbox',
        '#title' => t('Send invites only for <em>completed</em> orders'),
        '#default_value' => variable_get('webwinkelkeur_invite_completed_only', true),
    );
    $form['invites_options'] = array(
        '#type' => 'value',
        '#value' => array(
            1 => t('each order'),
            2 => t('first order only')
        ),
    );
    $form['invites']['invite_type'] = array(
        '#type' => 'radios',
        '#title' => t('Send invitations on'),
        '#options' => $form['invites_options']['#value'],
        '#default_value' => variable_get('webwinkelkeur_invite_type', 1),
    );
    $form['invites']['limit_order_data'] = array(
        '#type' => 'checkbox',
        '#title' => t('Do not send order information to WebwinkelKeur.'),
        '#description' => t('<p>Please note: not all WebwinkelKeur functionality will be available if you check this option!</p>'),
        '#default_value' => variable_get('webwinkelkeur_limit_order_data', false),
    );
    $form['invites']['invite_delay'] = array(
        '#type' => 'textfield',
        '#title' => t('Invitation delay'),
        '#default_value' => variable_get('webwinkelkeur_invite_delay', 0),
    );

    $form['#submit'][] = 'webwinkelkeur_invite_settings_submit';

    return system_settings_form($form);
}

function webwinkelkeur_invite_settings_submit($form, &$form_state) {
    variable_set('webwinkelkeur_invite_type', $form_state['values']['invite_type']);
    variable_set('webwinkelkeur_invite_delay', $form_state['values']['invite_delay']);
    variable_set('webwinkelkeur_invite_completed_only', $form_state['values']['invites_completed_only']);
    variable_set('webwinkelkeur_limit_order_data', $form_state['values']['limit_order_data']);
}

