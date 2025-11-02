#include "aquarite.h"
#include "esphome/components/number/number.h"
#include "esphome/components/binary_sensor/binary_sensor.h"

namespace esphome {
namespace aquarite {

static const char *TAG = "aquarite";

// Setup function to register all sensors and entities
void setup_aquarite(AquaRiteComponent *comp, UARTComponent *uart) {
  comp->uart_ = uart;

  // --- Sensors ---
  comp->salt_ppm_sensor->set_name("AquaRite Salt PPM");
  comp->temp_sensor->set_name("AquaRite Water Temperature");
  comp->voltage_sensor->set_name("AquaRite Cell Voltage");
  comp->current_sensor->set_name("AquaRite Cell Current");
  comp->error_code_sensor->set_name("AquaRite Error Code");
  comp->output_sensor->set_name("AquaRite Output %");
  comp->cell_efficiency_sensor->set_name("AquaRite Cell Efficiency %");

  App.register_component(comp->salt_ppm_sensor);
  App.register_component(comp->temp_sensor);
  App.register_component(comp->voltage_sensor);
  App.register_component(comp->current_sensor);
  App.register_component(comp->error_code_sensor);
  App.register_component(comp->output_sensor);
  App.register_component(comp->cell_efficiency_sensor);

  // --- Binary sensors ---
  comp->flow_ok->set_name("AquaRite Flow OK");
  comp->check_cell->set_name("AquaRite Check Cell");
  comp->polarity_reversed->set_name("AquaRite Polarity Reversed");
  comp->over_temp->set_name("AquaRite Over Temp");
  comp->sensor_error->set_name("AquaRite Sensor Error");

  App.register_component(comp->flow_ok);
  App.register_component(comp->check_cell);
  App.register_component(comp->polarity_reversed);
  App.register_component(comp->over_temp);
  App.register_component(comp->sensor_error);

  // --- Number entity for output control ---
  auto *num = new number::TemplateNumber();
  num->set_name("AquaRite Set Output %");
  num->set_min_value(0);
  num->set_max_value(100);
  num->set_step(1);
  num->set_optimistic(true);

  num->add_on_state_callback([comp](float x) {
    comp->set_output_percent(x);
  });

  comp->output_control = num;
  App.register_component(num);

  // --- Register the main component for polling ---
  App.register_component(comp);

  ESP_LOGI(TAG, "AquaRite component setup complete with robust RS485 handling");
}

}  // namespace aquarite
}  // namespace esphome
