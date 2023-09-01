//Starlight/Twinkle effects by @bactaholic
//-------------------STAR LIGHT -----------------------------------------//
#ifdef ENABLE_RGB_MATRIX_STAR_LIGHT
RGB_MATRIX_EFFECT(STAR_LIGHT)
#    ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static void star_light_set_color(int i, effect_params_t* params) {
    if (!HAS_ANY_FLAGS(g_led_config.flags[i], params->flags)) return;
        HSV hsv = rgb_matrix_config.hsv;
        uint16_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 8);
        hsv.v = scale8(abs8(sin8(time) - 128) * 2, hsv.v);
        RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
}

bool STAR_LIGHT(effect_params_t* params) {
    if (!params->init) {
        if (scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed, 5)) % 5 == 0) {
            star_light_set_color(rand() % RGBLED_NUM, params);
        }
        return false;
    }

    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (int i = led_min; i < led_max; i++) {
        star_light_set_color(i, params);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif      // ENABLE_RGB_MATRIX_STAR_LIGHT

#ifdef ENABLE_RGB_MATRIX_HOME_ROW_TWINKLE
RGB_MATRIX_EFFECT(HOME_ROW_TWINKLE)
#   ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

uint8_t rgb_groups[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, //->
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    //<-
    0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0,    //->
    0, 0, 2, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 0,       //<-
    0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 3, 0,       //->
    3, 3, 3, 0, 0, 0, 0, 0, 0, 0                    //<-
};

// static HSV HUE_WAVE_math(HSV hsv, uint8_t i, uint8_t time) {
//     uint8_t huedelta = 30;
//     hsv.h            = hsv.h + scale8(abs8(g_led_config.point[i].x - time), huedelta);
//     return hsv;
// }

// static HSV HUE_PENDULUM_math(HSV hsv, uint8_t i, uint8_t time) {
//     uint8_t huedelta = 30;
//     hsv.h            = hsv.h + scale8(abs8(sin8(time) + (g_led_config.point[i].x) - 128) * 2, huedelta);
//     return hsv;
// }



bool HOME_ROW_TWINKLE(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        HSV hsv = {HSV_OFF};
        RGB rgb = {RGB_OFF};
        uint8_t time = scale16by8(g_rgb_timer,qadd8(rgb_matrix_config.speed /8,1));
        switch (rgb_groups[i])
        {
        case 0: //Background color
            hsv = rgb_matrix_config.hsv;
            int16_t dx = g_led_config.point[i].x - g_led_config.point[65].x;
            int16_t dy = g_led_config.point[i].y - g_led_config.point[65].y;
            uint8_t dist = sqrt16(dx*dx + dy*dy);
            hsv.h = addmod8(hsv.h+time,dist/4,255);
            rgb = rgb_matrix_hsv_to_rgb(hsv);
            rgb_matrix_set_color(i,rgb.r,rgb.g,rgb.b);

            break;
        case 1: //Homerow
            hsv = rgb_matrix_config.hsv;
            hsv.h = addmod8(hsv.h,85,255);
            rgb = rgb_matrix_hsv_to_rgb(hsv);
            rgb_matrix_set_color(i,rgb.r,rgb.g,rgb.b);
            break;
        case 2: //Other main keys
            rgb = rgb_matrix_hsv_to_rgb(rgb_matrix_config.hsv);
            rgb_matrix_set_color(i,rgb.r,rgb.g,rgb.b);
            break;
        case 3: //Arrows
            hsv = rgb_matrix_config.hsv;
            hsv.h = addmod8(hsv.h,170,255);
            rgb = rgb_matrix_hsv_to_rgb(hsv);
            rgb_matrix_set_color(i,rgb.r,rgb.g,rgb.b);
            break;
        case 4:
            break;
        default:
            break;
        }
    }

    return rgb_matrix_check_finished_leds(led_max);
}

#   endif //RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif //ENABLE_RGB_MATRIX_HOME_ROW_TWINKLE
