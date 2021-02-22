.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241E50_A4A410
/* A4A410 80241E50 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A4A414 80241E54 AFB10014 */  sw        $s1, 0x14($sp)
/* A4A418 80241E58 0080882D */  daddu     $s1, $a0, $zero
/* A4A41C 80241E5C 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* A4A420 80241E60 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* A4A424 80241E64 AFBF0018 */  sw        $ra, 0x18($sp)
/* A4A428 80241E68 AFB00010 */  sw        $s0, 0x10($sp)
/* A4A42C 80241E6C 84430018 */  lh        $v1, 0x18($v0)
/* A4A430 80241E70 04600005 */  bltz      $v1, .L80241E88
/* A4A434 80241E74 0040802D */   daddu    $s0, $v0, $zero
/* A4A438 80241E78 3C05FD05 */  lui       $a1, 0xfd05
/* A4A43C 80241E7C 34A50F80 */  ori       $a1, $a1, 0xf80
/* A4A440 80241E80 0C0B2026 */  jal       set_variable
/* A4A444 80241E84 0000302D */   daddu    $a2, $zero, $zero
.L80241E88:
/* A4A448 80241E88 86020018 */  lh        $v0, 0x18($s0)
/* A4A44C 80241E8C 2842FEE9 */  slti      $v0, $v0, -0x117
/* A4A450 80241E90 10400005 */  beqz      $v0, .L80241EA8
/* A4A454 80241E94 0220202D */   daddu    $a0, $s1, $zero
/* A4A458 80241E98 3C05FD05 */  lui       $a1, 0xfd05
/* A4A45C 80241E9C 34A50F80 */  ori       $a1, $a1, 0xf80
/* A4A460 80241EA0 0C0B2026 */  jal       set_variable
/* A4A464 80241EA4 24060001 */   addiu    $a2, $zero, 1
.L80241EA8:
/* A4A468 80241EA8 8FBF0018 */  lw        $ra, 0x18($sp)
/* A4A46C 80241EAC 8FB10014 */  lw        $s1, 0x14($sp)
/* A4A470 80241EB0 8FB00010 */  lw        $s0, 0x10($sp)
/* A4A474 80241EB4 0000102D */  daddu     $v0, $zero, $zero
/* A4A478 80241EB8 03E00008 */  jr        $ra
/* A4A47C 80241EBC 27BD0020 */   addiu    $sp, $sp, 0x20
