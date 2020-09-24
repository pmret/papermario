.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003F084
/* 1A484 8003F084 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1A488 8003F088 AFBF0010 */  sw        $ra, 0x10($sp)
/* 1A48C 8003F08C 0C00EABB */  jal       get_npc_unsafe
/* 1A490 8003F090 2404FFF6 */   addiu    $a0, $zero, -0xa
/* 1A494 8003F094 0040182D */  daddu     $v1, $v0, $zero
/* 1A498 8003F098 906200AC */  lbu       $v0, 0xac($v1)
/* 1A49C 8003F09C 2442FFEF */  addiu     $v0, $v0, -0x11
/* 1A4A0 8003F0A0 A06200AC */  sb        $v0, 0xac($v1)
/* 1A4A4 8003F0A4 304200FF */  andi      $v0, $v0, 0xff
/* 1A4A8 8003F0A8 14400003 */  bnez      $v0, .L8003F0B8
/* 1A4AC 8003F0AC 0000102D */   daddu    $v0, $zero, $zero
/* 1A4B0 8003F0B0 A06000AC */  sb        $zero, 0xac($v1)
/* 1A4B4 8003F0B4 24020001 */  addiu     $v0, $zero, 1
.L8003F0B8:
/* 1A4B8 8003F0B8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 1A4BC 8003F0BC 03E00008 */  jr        $ra
/* 1A4C0 8003F0C0 27BD0018 */   addiu    $sp, $sp, 0x18
