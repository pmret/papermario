.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F50_D7A940
/* D7A940 80240F50 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D7A944 80240F54 AFB00010 */  sw        $s0, 0x10($sp)
/* D7A948 80240F58 3C108024 */  lui       $s0, %hi(D_80241690)
/* D7A94C 80240F5C 26101690 */  addiu     $s0, $s0, %lo(D_80241690)
/* D7A950 80240F60 AFBF0018 */  sw        $ra, 0x18($sp)
/* D7A954 80240F64 AFB10014 */  sw        $s1, 0x14($sp)
/* D7A958 80240F68 8E020000 */  lw        $v0, ($s0)
/* D7A95C 80240F6C 14400010 */  bnez      $v0, .L80240FB0
/* D7A960 80240F70 0080882D */   daddu    $s1, $a0, $zero
/* D7A964 80240F74 0C00AB39 */  jal       heap_malloc
/* D7A968 80240F78 24040040 */   addiu    $a0, $zero, 0x40
/* D7A96C 80240F7C AE020000 */  sw        $v0, ($s0)
/* D7A970 80240F80 0000182D */  daddu     $v1, $zero, $zero
/* D7A974 80240F84 0040282D */  daddu     $a1, $v0, $zero
/* D7A978 80240F88 0220202D */  daddu     $a0, $s1, $zero
.L80240F8C:
/* D7A97C 80240F8C 8C820084 */  lw        $v0, 0x84($a0)
/* D7A980 80240F90 24840004 */  addiu     $a0, $a0, 4
/* D7A984 80240F94 24630001 */  addiu     $v1, $v1, 1
/* D7A988 80240F98 ACA20000 */  sw        $v0, ($a1)
/* D7A98C 80240F9C 28620010 */  slti      $v0, $v1, 0x10
/* D7A990 80240FA0 1440FFFA */  bnez      $v0, .L80240F8C
/* D7A994 80240FA4 24A50004 */   addiu    $a1, $a1, 4
/* D7A998 80240FA8 080903FB */  j         .L80240FEC
/* D7A99C 80240FAC 00000000 */   nop      
.L80240FB0:
/* D7A9A0 80240FB0 0000182D */  daddu     $v1, $zero, $zero
/* D7A9A4 80240FB4 0040282D */  daddu     $a1, $v0, $zero
/* D7A9A8 80240FB8 0220202D */  daddu     $a0, $s1, $zero
.L80240FBC:
/* D7A9AC 80240FBC 8CA20000 */  lw        $v0, ($a1)
/* D7A9B0 80240FC0 24A50004 */  addiu     $a1, $a1, 4
/* D7A9B4 80240FC4 24630001 */  addiu     $v1, $v1, 1
/* D7A9B8 80240FC8 AC820084 */  sw        $v0, 0x84($a0)
/* D7A9BC 80240FCC 28620010 */  slti      $v0, $v1, 0x10
/* D7A9C0 80240FD0 1440FFFA */  bnez      $v0, .L80240FBC
/* D7A9C4 80240FD4 24840004 */   addiu    $a0, $a0, 4
/* D7A9C8 80240FD8 3C108024 */  lui       $s0, %hi(D_80241690)
/* D7A9CC 80240FDC 26101690 */  addiu     $s0, $s0, %lo(D_80241690)
/* D7A9D0 80240FE0 0C00AB4B */  jal       heap_free
/* D7A9D4 80240FE4 8E040000 */   lw       $a0, ($s0)
/* D7A9D8 80240FE8 AE000000 */  sw        $zero, ($s0)
.L80240FEC:
/* D7A9DC 80240FEC 8FBF0018 */  lw        $ra, 0x18($sp)
/* D7A9E0 80240FF0 8FB10014 */  lw        $s1, 0x14($sp)
/* D7A9E4 80240FF4 8FB00010 */  lw        $s0, 0x10($sp)
/* D7A9E8 80240FF8 24020002 */  addiu     $v0, $zero, 2
/* D7A9EC 80240FFC 03E00008 */  jr        $ra
/* D7A9F0 80241000 27BD0020 */   addiu    $sp, $sp, 0x20
