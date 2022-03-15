void tick();

void une_fonction() {
	tick();
}

__attribute__((interrupt))

void un_traitant() {
	tick();
}
