/*
    Copyright (c) 2014, Anonymous Meerkat <meerkatanonymous@gmail.com>
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
        * Redistributions of source code must retain the above copyright
          notice, this list of conditions and the following disclaimer.
        * Redistributions in binary form must reproduce the above copyright
          notice, this list of conditions and the following disclaimer in the
          documentation and/or other materials provided with the distribution.
        * Neither the name of the Nightmare Project nor the
          names of its contributors may be used to endorse or promote products
          derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL ANONYMOUS MEERKAT BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "NOSAPI.h"

#include <sys/time.h>
#include <unistd.h>

bool lin_init() {
    return true;
}

bool lin_destroy() {
    return true;
}


uint lin_get_millis() {
    struct timeval tv;
    gettimeofday(&tv, NULL); /// Replace to clock_gettime()
                              // FreeBSD: CLOCK_UPTIME_FAST or CLOCK_MONOTONIC_FAST
                              // Linux: CLOCK_MONOTONIC_RAW, then CLOCK_MONOTONIC_COARSE
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

void lin_sleep(uint millis) {
    usleep(millis * 1000);
}


NOSAPI_t N_OSAPI_Linux = {
    .init = lin_init,
    .destroy = lin_destroy,

    .get_millis = lin_get_millis,
    .sleep = lin_sleep
};
