#include <iostream>

#include <oatpp-test/api/server.h>

#include "app_component.h"

#include <oatpp-swagger/Controller.hpp>
#include <oatpp/core/base/Environment.hpp>

#include <oatpp/network/Server.hpp>

#include "controller/status_controller.h"

void Server::run() {

  oatpp::base::Environment::init();

  AppComponent components;

  auto router = components.httpRouter.getObject();
  auto docEndpoints = oatpp::swagger::Controller::Endpoints::createShared();

  auto statusController = StatusController::createShared();
  statusController->addEndpointsToRouter(router);

  docEndpoints->pushBackAll(statusController->getEndpoints());

  auto swaggerController =
      oatpp::swagger::Controller::createShared(docEndpoints);

  swaggerController->addEndpointsToRouter(router);

  /* create server */

  oatpp::network::Server server(components.serverConnectionProvider.getObject(),
                                components.serverConnectionHandler.getObject());

  OATPP_LOGD("Server", "Running on port %s...",
             components.serverConnectionProvider.getObject()
                 ->getProperty("port")
                 .toString()
                 ->c_str());
  server.run();

  /* Print how much objects were created during app running, and what have
   * left-probably leaked */
  /* Disable object counting for release builds using '-D
   * OATPP_DISABLE_ENV_OBJECT_COUNTERS' flag for better performance */
  std::cout << "\nEnvironment:\n";
  std::cout << "objectsCount = " << oatpp::base::Environment::getObjectsCount()
            << "\n";
  std::cout << "objectsCreated = "
            << oatpp::base::Environment::getObjectsCreated() << "\n\n";

  oatpp::base::Environment::destroy();
}
