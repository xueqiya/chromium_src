/*
 * Copyright 2020 The Chromium Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

let paymentRequestResponder;
let paymentRequestEvent;
let methodName;

self.addEventListener('canmakepayment', (evt) => {
  evt.respondWith(true);
});

self.addEventListener('message', (evt) => {
  // Sent from the Payment app.
  if (evt.data === 'confirm') {
    paymentRequestResponder({methodName, details: {status: 'success'}});
    return;
  } else if (evt.data === 'cancel') {
    paymentRequestResponder({methodName, details: {status: 'fail'}});
    return;
  } else if (evt.data === 'app_is_ready') {
    paymentRequestEvent.changePaymentMethod(methodName, {
      status: evt.data,
    });
    return;
  }
});

self.addEventListener('paymentrequest', (evt) => {
  paymentRequestEvent = evt;
  methodName = evt.methodData[0].supportedMethods;
  evt.respondWith(new Promise((responder) => {
    paymentRequestResponder = responder;
    evt.openWindow('./payment_handler_window.html');
  }));
});
