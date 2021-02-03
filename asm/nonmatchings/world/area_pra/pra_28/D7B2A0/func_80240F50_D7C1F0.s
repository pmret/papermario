.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F50_D7C1F0
/* D7C1F0 80240F50 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D7C1F4 80240F54 AFB00010 */  sw        $s0, 0x10($sp)
/* D7C1F8 80240F58 3C108024 */  lui       $s0, %hi(D_80241690_D7C930)
/* D7C1FC 80240F5C 26101690 */  addiu     $s0, $s0, %lo(D_80241690_D7C930)
/* D7C200 80240F60 AFBF0018 */  sw        $ra, 0x18($sp)
/* D7C204 80240F64 AFB10014 */  sw        $s1, 0x14($sp)
/* D7C208 80240F68 8E020000 */  lw        $v0, ($s0)
/* D7C20C 80240F6C 14400010 */  bnez      $v0, .L80240FB0
/* D7C210 80240F70 0080882D */   daddu    $s1, $a0, $zero
/* D7C214 80240F74 0C00AB39 */  jal       heap_malloc
/* D7C218 80240F78 24040040 */   addiu    $a0, $zero, 0x40
/* D7C21C 80240F7C AE020000 */  sw        $v0, ($s0)
/* D7C220 80240F80 0000182D */  daddu     $v1, $zero, $zero
/* D7C224 80240F84 0040282D */  daddu     $a1, $v0, $zero
/* D7C228 80240F88 0220202D */  daddu     $a0, $s1, $zero
.L80240F8C:
/* D7C22C 80240F8C 8C820084 */  lw        $v0, 0x84($a0)
/* D7C230 80240F90 24840004 */  addiu     $a0, $a0, 4
/* D7C234 80240F94 24630001 */  addiu     $v1, $v1, 1
/* D7C238 80240F98 ACA20000 */  sw        $v0, ($a1)
/* D7C23C 80240F9C 28620010 */  slti      $v0, $v1, 0x10
/* D7C240 80240FA0 1440FFFA */  bnez      $v0, .L80240F8C
/* D7C244 80240FA4 24A50004 */   addiu    $a1, $a1, 4
/* D7C248 80240FA8 080903FB */  j         .L80240FEC
/* D7C24C 80240FAC 00000000 */   nop
.L80240FB0:
/* D7C250 80240FB0 0000182D */  daddu     $v1, $zero, $zero
/* D7C254 80240FB4 0040282D */  daddu     $a1, $v0, $zero
/* D7C258 80240FB8 0220202D */  daddu     $a0, $s1, $zero
.L80240FBC:
/* D7C25C 80240FBC 8CA20000 */  lw        $v0, ($a1)
/* D7C260 80240FC0 24A50004 */  addiu     $a1, $a1, 4
/* D7C264 80240FC4 24630001 */  addiu     $v1, $v1, 1
/* D7C268 80240FC8 AC820084 */  sw        $v0, 0x84($a0)
/* D7C26C 80240FCC 28620010 */  slti      $v0, $v1, 0x10
/* D7C270 80240FD0 1440FFFA */  bnez      $v0, .L80240FBC
/* D7C274 80240FD4 24840004 */   addiu    $a0, $a0, 4
/* D7C278 80240FD8 3C108024 */  lui       $s0, %hi(D_80241690_D7C930)
/* D7C27C 80240FDC 26101690 */  addiu     $s0, $s0, %lo(D_80241690_D7C930)
/* D7C280 80240FE0 0C00AB4B */  jal       heap_free
/* D7C284 80240FE4 8E040000 */   lw       $a0, ($s0)
/* D7C288 80240FE8 AE000000 */  sw        $zero, ($s0)
.L80240FEC:
/* D7C28C 80240FEC 8FBF0018 */  lw        $ra, 0x18($sp)
/* D7C290 80240FF0 8FB10014 */  lw        $s1, 0x14($sp)
/* D7C294 80240FF4 8FB00010 */  lw        $s0, 0x10($sp)
/* D7C298 80240FF8 24020002 */  addiu     $v0, $zero, 2
/* D7C29C 80240FFC 03E00008 */  jr        $ra
/* D7C2A0 80241000 27BD0020 */   addiu    $sp, $sp, 0x20
