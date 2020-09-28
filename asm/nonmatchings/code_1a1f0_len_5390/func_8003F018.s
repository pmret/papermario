.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003F018
/* 1A418 8003F018 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1A41C 8003F01C AFB00010 */  sw        $s0, 0x10($sp)
/* 1A420 8003F020 00A0802D */  daddu     $s0, $a1, $zero
/* 1A424 8003F024 2404FFF6 */  addiu     $a0, $zero, -0xa
/* 1A428 8003F028 AFBF0018 */  sw        $ra, 0x18($sp)
/* 1A42C 8003F02C 0C00EABB */  jal       get_npc_unsafe
/* 1A430 8003F030 AFB10014 */   sw       $s1, 0x14($sp)
/* 1A434 8003F034 12000004 */  beqz      $s0, .L8003F048
/* 1A438 8003F038 0040882D */   daddu    $s1, $v0, $zero
/* 1A43C 8003F03C 0C05272D */  jal       play_sound
/* 1A440 8003F040 2404024B */   addiu    $a0, $zero, 0x24b
/* 1A444 8003F044 A22000AC */  sb        $zero, 0xac($s1)
.L8003F048:
/* 1A448 8003F048 922200AC */  lbu       $v0, 0xac($s1)
/* 1A44C 8003F04C 24420011 */  addiu     $v0, $v0, 0x11
/* 1A450 8003F050 A22200AC */  sb        $v0, 0xac($s1)
/* 1A454 8003F054 304200FF */  andi      $v0, $v0, 0xff
/* 1A458 8003F058 2C4200FF */  sltiu     $v0, $v0, 0xff
/* 1A45C 8003F05C 14400004 */  bnez      $v0, .L8003F070
/* 1A460 8003F060 0000102D */   daddu    $v0, $zero, $zero
/* 1A464 8003F064 240200FF */  addiu     $v0, $zero, 0xff
/* 1A468 8003F068 A22200AC */  sb        $v0, 0xac($s1)
/* 1A46C 8003F06C 24020001 */  addiu     $v0, $zero, 1
.L8003F070:
/* 1A470 8003F070 8FBF0018 */  lw        $ra, 0x18($sp)
/* 1A474 8003F074 8FB10014 */  lw        $s1, 0x14($sp)
/* 1A478 8003F078 8FB00010 */  lw        $s0, 0x10($sp)
/* 1A47C 8003F07C 03E00008 */  jr        $ra
/* 1A480 8003F080 27BD0020 */   addiu    $sp, $sp, 0x20
