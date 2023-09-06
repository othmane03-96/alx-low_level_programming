#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <elf.h>
int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        exit(98);
    }
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(98);
    }
    Elf64_Ehdr *ehdr = mmap(NULL, sizeof(Elf64_Ehdr), PROT_READ, MAP_PRIVATE, fd, 0);
    if (ehdr == MAP_FAILED) {
        perror("mmap");
        exit(98);
    }
    if (ehdr->e_ident[EI_MAG0] != ELFMAG0 ||
        ehdr->e_ident[EI_MAG1] != ELFMAG1 ||
        ehdr->e_ident[EI_MAG2] != ELFMAG2 ||
        ehdr->e_ident[EI_MAG3] != ELFMAG3) {
        fprintf(stderr, "%s: not an ELF file\n", argv[1]);
        exit(98);
    }
    printf("Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", ehdr->e_ident[i]);
    }
    printf("\n");
    printf("Class:                             ");
    switch (ehdr->e_ident[EI_CLASS]) {
    case ELFCLASS32:
        printf("ELF32\n");
        break;
    case ELFCLASS64:
        printf("ELF64\n");
        break;
    default:
        printf("unknown\n");
        break;
    }
    printf("Data:                              ");
    switch (ehdr->e_ident[EI_DATA]) {
    case ELFDATA2LSB:
        printf("2's complement, little
