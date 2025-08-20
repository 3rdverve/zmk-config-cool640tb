#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(vbat_enable, LOG_LEVEL_INF);

#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(vbat_enable, LOG_LEVEL_INF);

#/* XIAO BLE の VBAT_ENABLE は P0.14（GPIO0 の 14） */
static int vbat_enable_init(void)
{
    const struct device *gpio0 = DEVICE_DT_GET(DT_NODELABEL(gpio0));
    if (!device_is_ready(gpio0)) {
        return -ENODEV;
    }

 #   /* 初期から LOW 出力（分圧を有効化して AIN7 に電圧が入る） */
    gpio_pin_configure(gpio0, 14, GPIO_OUTPUT_INACTIVE);
 #   /* 念のため明示的に 0 をセット */
    gpio_pin_set(gpio0, 14, 0);

    LOG_INF("VBAT divider enabled (P0.14 set LOW).");
    return 0;
}

#/* ZMK 起動時に実行。APPLICATION(=アプリ層)で OK */
SYS_INIT(vbat_enable_init, APPLICATION, 50);
static int vbat_enable_init(void)
{
    const struct device *gpio0 = DEVICE_DT_GET(DT_NODELABEL(gpio0));
    if (!device_is_ready(gpio0)) {
        return -ENODEV;
    }

    # /* 初期から LOW 出力（分圧を有効化して AIN7 に電圧が入る） */
    gpio_pin_configure(gpio0, 14, GPIO_OUTPUT_INACTIVE);
    # /* 念のため明示的に 0 をセット */
    gpio_pin_set(gpio0, 14, 0);

    LOG_INF("VBAT divider enabled (P0.14 set LOW).");
    return 0;
}

# /* ZMK 起動時に実行。APPLICATION(=アプリ層)で OK */
SYS_INIT(vbat_enable_init, APPLICATION, 50);
