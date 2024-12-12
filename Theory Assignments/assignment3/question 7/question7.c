/*In a Netflix-like streaming platform, 2D pointers are used to dynamically manage and personalize
the viewing experience for millions of users across diverse content categories and device types.
The platform employs a 2D pointer structure, where each row represents a user profile, and each
column corresponds to a content category (e.g., Action, Drama, Comedy). A double**
engagementMatrix pointer points to this 2D array, where each element stores a numerical
engagement score (e.g., average viewing time or like/dislike ratio) for a user's interaction with that
category.
Each user profile structure includes a pointer to their respective row in the engagement matrix,
allowing for quick retrieval and updates of personalized data. For example,
engagementMatrix[userIndex][categoryIndex] can be updated whenever the user streams content
from a specific category, dynamically recalibrating their preferences in real-time.
The system also uses a secondary 2D pointer structure to manage device-specific preferences.
For instance, deviceMatrix[userIndex][deviceIndex] points to dynamically allocated arrays holding
resolution preferences, playback history, and bandwidth usage for different devices (smart TVs,
laptops, smartphones) associated with a user's profile. This enables seamless transitions between
devices while maintaining personalized settings like resolution and playback position.
Additionally, another 2D pointer system tracks content metadata, where each row corresponds to a
content category and each column represents a specific piece of content. Each element in this
matrix contains a pointer to a structure with attributes like title, rating, runtime, and encoding
formats, enabling quick access to metadata for streaming.
This multi-layered 2D pointer-based design allows the platform to efficiently store, retrieve, and
update personalized recommendations, device preferences, and content metadata. By leveraging
such dynamic data structures, the system delivers a highly tailored, device-optimized viewing
experience for users, ensuring maximum engagement and satisfaction while handling the scalability
needs of a global user base.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    float rating;
    int runtime;
    char encodingFormats[50];
} ContentMetadata;

typedef struct {
    float resolutionPreference;
    int playbackHistory[10];
    float bandwidthUsage;
} DevicePreferences;

typedef struct {
    double* engagementRow;
    DevicePreferences** devices;
    int numDevices;
} UserProfile;

void initializeEngagementMatrix(double*** matrix, int numUsers, int numCategories) {
    *matrix = (double**)malloc(numUsers * sizeof(double*));
    for (int i = 0; i < numUsers; i++) {
        (*matrix)[i] = (double*)calloc(numCategories, sizeof(double));
    }
}

void initializeDeviceMatrix(DevicePreferences**** deviceMatrix, int numUsers, int maxDevices) {
    *deviceMatrix = (DevicePreferences***)malloc(numUsers * sizeof(DevicePreferences**));
    for (int i = 0; i < numUsers; i++) {
        (*deviceMatrix)[i] = (DevicePreferences**)malloc(maxDevices * sizeof(DevicePreferences*));
        for (int j = 0; j < maxDevices; j++) {
            (*deviceMatrix)[i][j] = (DevicePreferences*)malloc(sizeof(DevicePreferences));
            (*deviceMatrix)[i][j]->resolutionPreference = 1080;
            (*deviceMatrix)[i][j]->bandwidthUsage = 0;
            memset((*deviceMatrix)[i][j]->playbackHistory, 0, 10 * sizeof(int));
        }
    }
}

void initializeContentMetadata(ContentMetadata*** contentMatrix, int numCategories, int numContents) {
    *contentMatrix = (ContentMetadata**)malloc(numCategories * sizeof(ContentMetadata*));
    for (int i = 0; i < numCategories; i++) {
        (*contentMatrix)[i] = (ContentMetadata*)malloc(numContents * sizeof(ContentMetadata));
        for (int j = 0; j < numContents; j++) {
            snprintf((*contentMatrix)[i][j].title, 100, "Content_%d_%d", i + 1, j + 1);
            (*contentMatrix)[i][j].rating = (rand() % 50) / 10.0 + 5.0;
            (*contentMatrix)[i][j].runtime = (rand() % 60) + 90;
            snprintf((*contentMatrix)[i][j].encodingFormats, 50, "HD, 4K");
        }
    }
}

void updateEngagementScore(double** matrix, int userIndex, int categoryIndex, double score) {
    matrix[userIndex][categoryIndex] += score;
}

void displayEngagementMatrix(double** matrix, int numUsers, int numCategories) {
    for (int i = 0; i < numUsers; i++) {
        printf("User %d: ", i + 1);
        for (int j = 0; j < numCategories; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void freeEngagementMatrix(double** matrix, int numUsers) {
    for (int i = 0; i < numUsers; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void freeDeviceMatrix(DevicePreferences*** deviceMatrix, int numUsers, int maxDevices) {
    for (int i = 0; i < numUsers; i++) {
        for (int j = 0; j < maxDevices; j++) {
            free(deviceMatrix[i][j]);
        }
        free(deviceMatrix[i]);
    }
    free(deviceMatrix);
}

void freeContentMetadata(ContentMetadata** contentMatrix, int numCategories, int numContents) {
    for (int i = 0; i < numCategories; i++) {
        free(contentMatrix[i]);
    }
    free(contentMatrix);
}

int main() {
    int numUsers = 3, numCategories = 5, maxDevices = 2, numContents = 4;

    double** engagementMatrix;
    initializeEngagementMatrix(&engagementMatrix, numUsers, numCategories);

    DevicePreferences*** deviceMatrix;
    initializeDeviceMatrix(&deviceMatrix, numUsers, maxDevices);

    ContentMetadata** contentMatrix;
    initializeContentMetadata(&contentMatrix, numCategories, numContents);

    updateEngagementScore(engagementMatrix, 0, 1, 5.0);
    updateEngagementScore(engagementMatrix, 1, 3, 3.5);

    displayEngagementMatrix(engagementMatrix, numUsers, numCategories);

    freeEngagementMatrix(engagementMatrix, numUsers);
    freeDeviceMatrix(deviceMatrix, numUsers, maxDevices);
    freeContentMetadata(contentMatrix, numCategories, numContents);

    return 0;
}