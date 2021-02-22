.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F50_D63C60
/* D63C60 80240F50 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D63C64 80240F54 AFB00010 */  sw        $s0, 0x10($sp)
/* D63C68 80240F58 3C108024 */  lui       $s0, %hi(D_802416B0_D643C0)
/* D63C6C 80240F5C 261016B0 */  addiu     $s0, $s0, %lo(D_802416B0_D643C0)
/* D63C70 80240F60 AFBF0018 */  sw        $ra, 0x18($sp)
/* D63C74 80240F64 AFB10014 */  sw        $s1, 0x14($sp)
/* D63C78 80240F68 8E020000 */  lw        $v0, ($s0)
/* D63C7C 80240F6C 14400010 */  bnez      $v0, .L80240FB0
/* D63C80 80240F70 0080882D */   daddu    $s1, $a0, $zero
/* D63C84 80240F74 0C00AB39 */  jal       heap_malloc
/* D63C88 80240F78 24040040 */   addiu    $a0, $zero, 0x40
/* D63C8C 80240F7C AE020000 */  sw        $v0, ($s0)
/* D63C90 80240F80 0000182D */  daddu     $v1, $zero, $zero
/* D63C94 80240F84 0040282D */  daddu     $a1, $v0, $zero
/* D63C98 80240F88 0220202D */  daddu     $a0, $s1, $zero
.L80240F8C:
/* D63C9C 80240F8C 8C820084 */  lw        $v0, 0x84($a0)
/* D63CA0 80240F90 24840004 */  addiu     $a0, $a0, 4
/* D63CA4 80240F94 24630001 */  addiu     $v1, $v1, 1
/* D63CA8 80240F98 ACA20000 */  sw        $v0, ($a1)
/* D63CAC 80240F9C 28620010 */  slti      $v0, $v1, 0x10
/* D63CB0 80240FA0 1440FFFA */  bnez      $v0, .L80240F8C
/* D63CB4 80240FA4 24A50004 */   addiu    $a1, $a1, 4
/* D63CB8 80240FA8 080903FB */  j         .L80240FEC
/* D63CBC 80240FAC 00000000 */   nop
.L80240FB0:
/* D63CC0 80240FB0 0000182D */  daddu     $v1, $zero, $zero
/* D63CC4 80240FB4 0040282D */  daddu     $a1, $v0, $zero
/* D63CC8 80240FB8 0220202D */  daddu     $a0, $s1, $zero
.L80240FBC:
/* D63CCC 80240FBC 8CA20000 */  lw        $v0, ($a1)
/* D63CD0 80240FC0 24A50004 */  addiu     $a1, $a1, 4
/* D63CD4 80240FC4 24630001 */  addiu     $v1, $v1, 1
/* D63CD8 80240FC8 AC820084 */  sw        $v0, 0x84($a0)
/* D63CDC 80240FCC 28620010 */  slti      $v0, $v1, 0x10
/* D63CE0 80240FD0 1440FFFA */  bnez      $v0, .L80240FBC
/* D63CE4 80240FD4 24840004 */   addiu    $a0, $a0, 4
/* D63CE8 80240FD8 3C108024 */  lui       $s0, %hi(D_802416B0_D643C0)
/* D63CEC 80240FDC 261016B0 */  addiu     $s0, $s0, %lo(D_802416B0_D643C0)
/* D63CF0 80240FE0 0C00AB4B */  jal       heap_free
/* D63CF4 80240FE4 8E040000 */   lw       $a0, ($s0)
/* D63CF8 80240FE8 AE000000 */  sw        $zero, ($s0)
.L80240FEC:
/* D63CFC 80240FEC 8FBF0018 */  lw        $ra, 0x18($sp)
/* D63D00 80240FF0 8FB10014 */  lw        $s1, 0x14($sp)
/* D63D04 80240FF4 8FB00010 */  lw        $s0, 0x10($sp)
/* D63D08 80240FF8 24020002 */  addiu     $v0, $zero, 2
/* D63D0C 80240FFC 03E00008 */  jr        $ra
/* D63D10 80241000 27BD0020 */   addiu    $sp, $sp, 0x20
