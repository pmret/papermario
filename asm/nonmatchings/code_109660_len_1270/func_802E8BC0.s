.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E8BC0
/* 10A440 802E8BC0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 10A444 802E8BC4 AFBF001C */  sw        $ra, 0x1c($sp)
/* 10A448 802E8BC8 AFB20018 */  sw        $s2, 0x18($sp)
/* 10A44C 802E8BCC AFB10014 */  sw        $s1, 0x14($sp)
/* 10A450 802E8BD0 AFB00010 */  sw        $s0, 0x10($sp)
/* 10A454 802E8BD4 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 10A458 802E8BD8 0C016AFA */  jal       get_current_map_header
/* 10A45C 802E8BDC 8C900040 */   lw       $s0, 0x40($a0)
/* 10A460 802E8BE0 0040902D */  daddu     $s2, $v0, $zero
/* 10A464 802E8BE4 8E02000C */  lw        $v0, 0xc($s0)
/* 10A468 802E8BE8 8E430014 */  lw        $v1, 0x14($s2)
/* 10A46C 802E8BEC 00021100 */  sll       $v0, $v0, 4
/* 10A470 802E8BF0 00431021 */  addu      $v0, $v0, $v1
/* 10A474 802E8BF4 C44C0000 */  lwc1      $f12, ($v0)
/* 10A478 802E8BF8 0C038022 */  jal       func_800E0088
/* 10A47C 802E8BFC C44E0008 */   lwc1     $f14, 8($v0)
/* 10A480 802E8C00 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* 10A484 802E8C04 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* 10A488 802E8C08 C462005C */  lwc1      $f2, 0x5c($v1)
/* 10A48C 802E8C0C 0060882D */  daddu     $s1, $v1, $zero
/* 10A490 802E8C10 46020003 */  div.s     $f0, $f0, $f2
/* 10A494 802E8C14 4600010D */  trunc.w.s $f4, $f0
/* 10A498 802E8C18 44022000 */  mfc1      $v0, $f4
/* 10A49C 802E8C1C 00000000 */  nop       
/* 10A4A0 802E8C20 14400003 */  bnez      $v0, .L802E8C30
/* 10A4A4 802E8C24 AE020004 */   sw       $v0, 4($s0)
/* 10A4A8 802E8C28 24020001 */  addiu     $v0, $zero, 1
/* 10A4AC 802E8C2C AE020004 */  sw        $v0, 4($s0)
.L802E8C30:
/* 10A4B0 802E8C30 C62C0028 */  lwc1      $f12, 0x28($s1)
/* 10A4B4 802E8C34 C62E0030 */  lwc1      $f14, 0x30($s1)
/* 10A4B8 802E8C38 8E02000C */  lw        $v0, 0xc($s0)
/* 10A4BC 802E8C3C 8E430014 */  lw        $v1, 0x14($s2)
/* 10A4C0 802E8C40 00021100 */  sll       $v0, $v0, 4
/* 10A4C4 802E8C44 00431021 */  addu      $v0, $v0, $v1
/* 10A4C8 802E8C48 8C460000 */  lw        $a2, ($v0)
/* 10A4CC 802E8C4C 0C00A720 */  jal       atan2
/* 10A4D0 802E8C50 8C470008 */   lw       $a3, 8($v0)
/* 10A4D4 802E8C54 0C03805E */  jal       disable_player_input
/* 10A4D8 802E8C58 46000506 */   mov.s    $f20, $f0
/* 10A4DC 802E8C5C 0C038045 */  jal       disable_player_static_collisions
/* 10A4E0 802E8C60 00000000 */   nop      
/* 10A4E4 802E8C64 8E26005C */  lw        $a2, 0x5c($s1)
/* 10A4E8 802E8C68 8E040004 */  lw        $a0, 4($s0)
/* 10A4EC 802E8C6C 4405A000 */  mfc1      $a1, $f20
/* 10A4F0 802E8C70 0C0389DE */  jal       move_player
/* 10A4F4 802E8C74 00000000 */   nop      
/* 10A4F8 802E8C78 8FBF001C */  lw        $ra, 0x1c($sp)
/* 10A4FC 802E8C7C 8FB20018 */  lw        $s2, 0x18($sp)
/* 10A500 802E8C80 8FB10014 */  lw        $s1, 0x14($sp)
/* 10A504 802E8C84 8FB00010 */  lw        $s0, 0x10($sp)
/* 10A508 802E8C88 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 10A50C 802E8C8C 03E00008 */  jr        $ra
/* 10A510 802E8C90 27BD0028 */   addiu    $sp, $sp, 0x28
