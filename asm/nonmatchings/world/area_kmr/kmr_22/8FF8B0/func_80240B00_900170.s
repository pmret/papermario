.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B00_900170
/* 900170 80240B00 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 900174 80240B04 3C028024 */  lui       $v0, 0x8024
/* 900178 80240B08 2442056C */  addiu     $v0, $v0, 0x56c
/* 90017C 80240B0C AFA2001C */  sw        $v0, 0x1c($sp)
/* 900180 80240B10 2402000A */  addiu     $v0, $zero, 0xa
/* 900184 80240B14 AFA20014 */  sw        $v0, 0x14($sp)
/* 900188 80240B18 24020001 */  addiu     $v0, $zero, 1
/* 90018C 80240B1C 27A40010 */  addiu     $a0, $sp, 0x10
/* 900190 80240B20 AFBF0020 */  sw        $ra, 0x20($sp)
/* 900194 80240B24 AFA00018 */  sw        $zero, 0x18($sp)
/* 900198 80240B28 0C047644 */  jal       queue_render_task
/* 90019C 80240B2C AFA20010 */   sw       $v0, 0x10($sp)
/* 9001A0 80240B30 8FBF0020 */  lw        $ra, 0x20($sp)
/* 9001A4 80240B34 03E00008 */  jr        $ra
/* 9001A8 80240B38 27BD0028 */   addiu    $sp, $sp, 0x28
