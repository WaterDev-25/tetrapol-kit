#pragma once

#include <stdio.h>

#include <tetrapol/frame.h>
#include <tetrapol/tetrapol_int.h>
#include <tetrapol/log.h>

/**
 * Dump frme as a JSON string.
 */
void frame_json(tpol_t *tpol, const frame_t *fr);

