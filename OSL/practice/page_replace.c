#include <stdio.h>
#include <stdlib.h>

struct page_ {
    int frequency;
    int value;
};

typedef struct page_ page;

page* create_page(int value) {

    page* pg = (page*) malloc(sizeof(page));
    pg->value = value;
    pg->frequency = 0;

    return pg;
}

struct page_frame {
    int size;
    int capacity;

    page** arr;
};

typedef struct page_frame frame;

frame* create_frame(int size) {

    frame* fr = (frame*) malloc(sizeof(frame));
    fr->size = 0;
    fr->capacity = size;

    fr->arr = (page**) malloc(sizeof(page*) * size);

    page* pf = create_page(-1);

    for(int i = 0; i < size; i++) {
        fr->arr[i] = pf;
    }

    return fr;
}

int least_used(frame* frames) {

    int min = -1;
    int min_index = -1;

    for(int i = 0; i < frames->size; i++) {

        //printf("fre %d\n", frames->arr[i]->frequency);

        if(frames->arr[i]->frequency > min) {
            
            min = frames->arr[i]->frequency;
            min_index = i;
        }

    }

    return min_index;
}

int found(frame* fr, page* pg) {

    for(int i = 0; i < fr->size; i++) {

        if(fr->arr[i]->value == pg->value)
            return i;
    }

    return -1;
}

//LRU

void increment_all(frame* frames) {

    for(int i = 0; i < frames->size; i++) {
        frames->arr[i]->frequency++;

    }
}

void lru_add(frame* frames, page* pg, int found) {

    if(found) {

        increment_all(frames);
        frames->arr[found]->frequency = 0;

    } else {

        if(frames->size == frames->capacity) {

            int index = least_used(frames);
            increment_all(frames);

            frames->arr[index] = pg;

        } else {
            frames->arr[frames->size++] = pg;
        }

    }

}

void lru_traverse(int ref[], int size) {

    frame* frames = create_frame(3);

    int faults = 0;

    for(int i = 0; i < size; i++) {

        page* pg = create_page(ref[i]);

        int index = found(frames, pg);

        if(index == -1) {
            faults++;
            printf("%d faulted\n", pg->value);

            lru_add(frames, pg, 0);

        } else {
            lru_add(frames, pg, index);
        }

    }

    printf("Page faults: %d\n", faults);
}

//FIFO

void fifo_add_page(frame* fr, page* pg) {

    if(fr->size == fr->capacity) {
        
        for(int i = 0; i < fr->size - 1; i++)
            fr->arr[i] = fr->arr[i + 1];
        
        fr->arr[fr->size - 1] = pg;

    } else {

        fr->arr[fr->size++] = pg;
    }

}

void traverse(int ref[], int size) {

    frame* fr = create_frame(3);

    int faults = 0;

    for(int i = 0; i < size; i++) {

        page* ref_pg = create_page(ref[i]);

        if(!found(fr, ref_pg)) {
            faults++;
        }

        fifo_add_page(fr, ref_pg);
    }

    printf("Page faults: %d\n", faults);
}

int main() {

    int ref[] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};

    lru_traverse(ref, 20);

    return 0;
    

}

