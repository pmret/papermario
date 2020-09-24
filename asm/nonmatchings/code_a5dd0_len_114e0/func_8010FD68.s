.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8010FD68
/* A6468 8010FD68 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A646C 8010FD6C AFB00010 */  sw        $s0, 0x10($sp)
/* A6470 8010FD70 0080802D */  daddu     $s0, $a0, $zero
/* A6474 8010FD74 AFBF0014 */  sw        $ra, 0x14($sp)
.L8010FD78:
/* A6478 8010FD78 0C043EF6 */  jal       func_8010FBD8
/* A647C 8010FD7C 0200202D */   daddu    $a0, $s0, $zero
/* A6480 8010FD80 1440FFFD */  bnez      $v0, .L8010FD78
/* A6484 8010FD84 00000000 */   nop      
/* A6488 8010FD88 8FBF0014 */  lw        $ra, 0x14($sp)
/* A648C 8010FD8C 8FB00010 */  lw        $s0, 0x10($sp)
/* A6490 8010FD90 03E00008 */  jr        $ra
/* A6494 8010FD94 27BD0018 */   addiu    $sp, $sp, 0x18
