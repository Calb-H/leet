
int maximumEnergy(int* energy, int energy_size, int k) {
    int max_energy = INT_MIN;
    int start_index = energy_size - 1; // start at the end of the array
    int index = 0;

    int min_start_index = energy_size - k;
    if (min_start_index < 0) {
        min_start_index = 0;
    }

    while (start_index >= min_start_index) {
        int path_max = 0;
        index = start_index;

        while (index >= 0) {
            path_max += energy[index];
            index -= k;

            if (path_max > max_energy) {
                max_energy = path_max;
            }
        }
        --start_index;
    }

    return max_energy;
}