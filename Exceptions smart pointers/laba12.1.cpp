#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

class GameResource {
public:
    std::string name;

    GameResource(const std::string& resourceName) : name(resourceName) {}

    virtual void load() = 0;
    virtual void release() = 0;

    virtual ~GameResource() = default;
};

class TextureResource : public GameResource {
public:
    TextureResource(const std::string& resourceName) : GameResource(resourceName) {}

    void load() override {
        std::cout << "Loading texture: " << name << std::endl;
    }

    void release() override {
        std::cout << "Releasing texture: " << name << std::endl;
    }
};


class AudioResource : public GameResource {
public:
    AudioResource(const std::string& resourceName) : GameResource(resourceName) {}

    void load() override {
        std::cout << "Loading audio: " << name << std::endl;
    }

    void release() override {
        std::cout << "Releasing audio: " << name << std::endl;
    }
};

class MeshResource : public GameResource {
public:
    MeshResource(const std::string& resourceName) : GameResource(resourceName) {}

    void load() override {
        std::cout << "Loading mesh: " << name << std::endl;
    }

    void release() override {
        std::cout << "Releasing mesh: " << name << std::endl;
    }
};


class ResourceManager {
private:
    std::vector<std::shared_ptr<GameResource>> resources;
    std::ofstream logFile;

public:
    ResourceManager() {
        logFile.open("resource_manager.log", std::ios::app);
        if (!logFile.is_open()) {
            std::cerr << "Error opening log file!" << std::endl;
        }
    }

    ~ResourceManager() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }

    void log(const std::string& message) const {
        std::cout << message << std::endl;
       
    }

    void loadResource(std::shared_ptr<GameResource> resource) {
        try {
            resource->load();
            resources.push_back(resource);
            log("Resource loaded: " + resource->name);
        }
        catch (const std::exception& e) {
            log("Error while loading resource: " + std::string(e.what()));
        }
    }

    void releaseResource(std::shared_ptr<GameResource> resource) {
        try {
            resource->release();
            auto it = std::remove(resources.begin(), resources.end(), resource);
            resources.erase(it, resources.end());
            log("Resource released: " + resource->name);
        }
        catch (const std::exception& e) {
            log("Error while releasing resource: " + std::string(e.what()));
        }
    }

    bool releaseResourceByName(const std::string& resourceName) {
        for (auto it = resources.begin(); it != resources.end(); ++it) {
            if ((*it)->name == resourceName) {
                releaseResource(*it);
                return true;
            }
        }
        return false;
    }

    void displayResources() const {
        log("Current resources:");
        for (const auto& resource : resources) {
            log("- " + resource->name);
        }
    }

    void autoReleaseResources() {
        resources.erase(std::remove_if(resources.begin(), resources.end(),
            [](const std::shared_ptr<GameResource>& resource) {
                return resource.use_count() == 1; 
            }), resources.end());
    }
};

void interactiveMenu(ResourceManager& resourceManager) {
    int choice;
    std::string resourceName;
    while (true) {
        std::cout << "\n1. Load Texture\n2. Load Audio\n3. Load Mesh\n4. Release Resource\n5. Display Resources\n6. Exit\nChoose an option: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter texture name: ";
            std::cin >> resourceName;
            resourceManager.loadResource(std::make_shared<TextureResource>(resourceName));
            break;
        case 2:
            std::cout << "Enter audio name: ";
            std::cin >> resourceName;
            resourceManager.loadResource(std::make_shared<AudioResource>(resourceName));
            break;
        case 3:
            std::cout << "Enter mesh name: ";
            std::cin >> resourceName;
            resourceManager.loadResource(std::make_shared<MeshResource>(resourceName));
            break;
        case 4:
            std::cout << "Enter resource name to release: ";
            std::cin >> resourceName;
            if (!resourceManager.releaseResourceByName(resourceName)) {
                std::cout << "Resource not found: " << resourceName << std::endl;
            }
            break;
        case 5:
            resourceManager.displayResources();
            break;
        case 6:
            resourceManager.autoReleaseResources();
            return;
        default:
            std::cout << "Invalid choice, please try again." << std::endl;
        }
    }
}

int main() {
    ResourceManager resourceManager;

    interactiveMenu(resourceManager);

    return 0;
}




