#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for each song
struct Song {
    char name[100];
    struct Song* prev;
    struct Song* next;
};


struct Song* createSong(char name[]) {
    struct Song* newSong = (struct Song*)malloc(sizeof(struct Song));
    strcpy(newSong->name, name);
    newSong->prev = NULL;
    newSong->next = NULL;
    return newSong;
}


struct Song* addSong(struct Song* head, char name[]) {
    struct Song* newSong = createSong(name);
    if (head == NULL)
        return newSong;

    struct Song* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newSong;
    newSong->prev = temp;
    return head;
}


void displayPlaylist(struct Song* head) {
    printf("\n🎵 Playlist:\n");
    if (head == NULL) {
        printf("No songs in playlist.\n");
        return;
    }

    struct Song* temp = head;
    while (temp != NULL) {
        printf("%s\n", temp->name);
        temp = temp->next;
    }
}

// Play next song
struct Song* playNext(struct Song* current) {
    if (current == NULL || current->next == NULL) {
        printf("No next song available.\n");
        return current;
    }
    current = current->next;
    printf("▶ Now Playing: %s\n", current->name);
    return current;
}

// Play previous song
struct Song* playPrevious(struct Song* current) {
    if (current == NULL || current->prev == NULL) {
        printf("No previous song available.\n");
        return current;
    }
    current = current->prev;
    printf(" Now Playing: %s\n", current->name);
    return current;
}

// Delete a song by name
struct Song* deleteSong(struct Song* head, char name[]) {
    if (head == NULL) {
        printf("Playlist is empty.\n");
        return NULL;
    }

    struct Song* temp = head;

    while (temp != NULL && strcmp(temp->name, name) != 0)
        temp = temp->next;

    if (temp == NULL) {
        printf("Song not found.\n");
        return head;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf(" Song deleted successfully.\n");
    return head;
}

// Main function
int main() {
    struct Song* head = NULL;
    struct Song* currentSong = NULL;
    int choice;
    char name[100];

    while (1) {
        printf("\n Music Player Menu \n");
        printf("1. Add Song\n");
        printf("2. Display Playlist\n");
        printf("3. Play Next Song\n");
        printf("4. Play Previous Song\n");
        printf("5. Delete Song\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // to consume newline after scanf

        switch (choice) {
            case 1:
                printf("Enter song name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;  // remove newline
                head = addSong(head, name);
                if (currentSong == NULL)
                    currentSong = head;
                break;

            case 2:
                displayPlaylist(head);
                break;

            case 3:
                currentSong = playNext(currentSong);
                break;

            case 4:
                currentSong = playPrevious(currentSong);
                break;

            case 5:
                printf("Enter song name to delete: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                head = deleteSong(head, name);
                if (currentSong != NULL && strcmp(currentSong->name, name) == 0)
                    currentSong = head;
                break;

            case 6:
                printf(" Exiting music player. Goodbye!\n");
                return 0;

            default:
                printf(" Invalid choice. Try again.\n");
        }
    }

    return 0;
}
