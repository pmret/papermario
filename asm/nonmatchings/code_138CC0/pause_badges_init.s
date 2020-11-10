.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_badges_init
/* 13C300 80248FC0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 13C304 80248FC4 AFB3001C */  sw        $s3, 0x1c($sp)
/* 13C308 80248FC8 0080982D */  daddu     $s3, $a0, $zero
/* 13C30C 80248FCC AFBF0020 */  sw        $ra, 0x20($sp)
/* 13C310 80248FD0 AFB20018 */  sw        $s2, 0x18($sp)
/* 13C314 80248FD4 AFB10014 */  sw        $s1, 0x14($sp)
/* 13C318 80248FD8 0C091C15 */  jal       pause_badges_count_all
/* 13C31C 80248FDC AFB00010 */   sw       $s0, 0x10($sp)
/* 13C320 80248FE0 3C018027 */  lui       $at, 0x8027
/* 13C324 80248FE4 AC200398 */  sw        $zero, 0x398($at)
/* 13C328 80248FE8 3C018027 */  lui       $at, 0x8027
/* 13C32C 80248FEC AC20039C */  sw        $zero, 0x39c($at)
/* 13C330 80248FF0 3C018027 */  lui       $at, 0x8027
/* 13C334 80248FF4 AC2003A0 */  sw        $zero, 0x3a0($at)
/* 13C338 80248FF8 0C092363 */  jal       pause_badges_load_badges
/* 13C33C 80248FFC 0000202D */   daddu    $a0, $zero, $zero
/* 13C340 80249000 3C038027 */  lui       $v1, %hi(gBadgeMenuItemIDs)
/* 13C344 80249004 84630180 */  lh        $v1, %lo(gBadgeMenuItemIDs)($v1)
/* 13C348 80249008 24027FFE */  addiu     $v0, $zero, 0x7ffe
/* 13C34C 8024900C 14620003 */  bne       $v1, $v0, .L8024901C
/* 13C350 80249010 0000802D */   daddu    $s0, $zero, $zero
/* 13C354 80249014 08092423 */  j         .L8024908C
/* 13C358 80249018 A2600000 */   sb       $zero, ($s3)
.L8024901C:
/* 13C35C 8024901C 3C128027 */  lui       $s2, 0x8027
/* 13C360 80249020 265203A8 */  addiu     $s2, $s2, 0x3a8
/* 13C364 80249024 3C118025 */  lui       $s1, 0x8025
/* 13C368 80249028 2631F4D0 */  addiu     $s1, $s1, -0xb30
.L8024902C:
/* 13C36C 8024902C 8E240000 */  lw        $a0, ($s1)
/* 13C370 80249030 26310004 */  addiu     $s1, $s1, 4
/* 13C374 80249034 0C050529 */  jal       create_icon
/* 13C378 80249038 26100001 */   addiu    $s0, $s0, 1
/* 13C37C 8024903C 0040202D */  daddu     $a0, $v0, $zero
/* 13C380 80249040 24050080 */  addiu     $a1, $zero, 0x80
/* 13C384 80249044 0C051280 */  jal       set_icon_flags
/* 13C388 80249048 AE440000 */   sw       $a0, ($s2)
/* 13C38C 8024904C 2A020016 */  slti      $v0, $s0, 0x16
/* 13C390 80249050 1440FFF6 */  bnez      $v0, .L8024902C
/* 13C394 80249054 26520004 */   addiu    $s2, $s2, 4
/* 13C398 80249058 0000802D */  daddu     $s0, $zero, $zero
/* 13C39C 8024905C 3C028025 */  lui       $v0, 0x8025
/* 13C3A0 80249060 2442F528 */  addiu     $v0, $v0, -0xad8
.L80249064:
/* 13C3A4 80249064 AC530010 */  sw        $s3, 0x10($v0)
/* 13C3A8 80249068 26100001 */  addiu     $s0, $s0, 1
/* 13C3AC 8024906C 1A00FFFD */  blez      $s0, .L80249064
/* 13C3B0 80249070 24420024 */   addiu    $v0, $v0, 0x24
/* 13C3B4 80249074 3C048025 */  lui       $a0, 0x8025
/* 13C3B8 80249078 2484F528 */  addiu     $a0, $a0, -0xad8
/* 13C3BC 8024907C 0C051FCC */  jal       func_80147F30
/* 13C3C0 80249080 24050001 */   addiu    $a1, $zero, 1
/* 13C3C4 80249084 24020001 */  addiu     $v0, $zero, 1
/* 13C3C8 80249088 A2620000 */  sb        $v0, ($s3)
.L8024908C:
/* 13C3CC 8024908C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 13C3D0 80249090 8FB3001C */  lw        $s3, 0x1c($sp)
/* 13C3D4 80249094 8FB20018 */  lw        $s2, 0x18($sp)
/* 13C3D8 80249098 8FB10014 */  lw        $s1, 0x14($sp)
/* 13C3DC 8024909C 8FB00010 */  lw        $s0, 0x10($sp)
/* 13C3E0 802490A0 03E00008 */  jr        $ra
/* 13C3E4 802490A4 27BD0028 */   addiu    $sp, $sp, 0x28
