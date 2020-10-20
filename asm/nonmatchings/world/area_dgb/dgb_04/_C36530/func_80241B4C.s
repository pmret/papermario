.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241B4C
/* C3807C 80241B4C 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* C38080 80241B50 AFB20048 */  sw        $s2, 0x48($sp)
/* C38084 80241B54 0080902D */  daddu     $s2, $a0, $zero
/* C38088 80241B58 AFBF004C */  sw        $ra, 0x4c($sp)
/* C3808C 80241B5C AFB10044 */  sw        $s1, 0x44($sp)
/* C38090 80241B60 AFB00040 */  sw        $s0, 0x40($sp)
/* C38094 80241B64 F7B40050 */  sdc1      $f20, 0x50($sp)
/* C38098 80241B68 8E500148 */  lw        $s0, 0x148($s2)
/* C3809C 80241B6C 0C00EABB */  jal       get_npc_unsafe
/* C380A0 80241B70 86040008 */   lh       $a0, 8($s0)
/* C380A4 80241B74 27A50028 */  addiu     $a1, $sp, 0x28
/* C380A8 80241B78 0040882D */  daddu     $s1, $v0, $zero
/* C380AC 80241B7C 27A6002C */  addiu     $a2, $sp, 0x2c
/* C380B0 80241B80 27A70030 */  addiu     $a3, $sp, 0x30
/* C380B4 80241B84 C620003C */  lwc1      $f0, 0x3c($s1)
/* C380B8 80241B88 3C014004 */  lui       $at, 0x4004
/* C380BC 80241B8C 44811800 */  mtc1      $at, $f3
/* C380C0 80241B90 44801000 */  mtc1      $zero, $f2
/* C380C4 80241B94 C6260038 */  lwc1      $f6, 0x38($s1)
/* C380C8 80241B98 46000021 */  cvt.d.s   $f0, $f0
/* C380CC 80241B9C 46220000 */  add.d     $f0, $f0, $f2
/* C380D0 80241BA0 3C01447A */  lui       $at, 0x447a
/* C380D4 80241BA4 44812000 */  mtc1      $at, $f4
/* C380D8 80241BA8 C6020078 */  lwc1      $f2, 0x78($s0)
/* C380DC 80241BAC 468010A0 */  cvt.s.w   $f2, $f2
/* C380E0 80241BB0 46200020 */  cvt.s.d   $f0, $f0
/* C380E4 80241BB4 E620003C */  swc1      $f0, 0x3c($s1)
/* C380E8 80241BB8 46000206 */  mov.s     $f8, $f0
/* C380EC 80241BBC C6200040 */  lwc1      $f0, 0x40($s1)
/* C380F0 80241BC0 27A20034 */  addiu     $v0, $sp, 0x34
/* C380F4 80241BC4 E7A00030 */  swc1      $f0, 0x30($sp)
/* C380F8 80241BC8 3C014059 */  lui       $at, 0x4059
/* C380FC 80241BCC 44810800 */  mtc1      $at, $f1
/* C38100 80241BD0 44800000 */  mtc1      $zero, $f0
/* C38104 80241BD4 460010A1 */  cvt.d.s   $f2, $f2
/* C38108 80241BD8 E7A60028 */  swc1      $f6, 0x28($sp)
/* C3810C 80241BDC E7A40034 */  swc1      $f4, 0x34($sp)
/* C38110 80241BE0 E7A8002C */  swc1      $f8, 0x2c($sp)
/* C38114 80241BE4 AFA20010 */  sw        $v0, 0x10($sp)
/* C38118 80241BE8 8E240080 */  lw        $a0, 0x80($s1)
/* C3811C 80241BEC 46201083 */  div.d     $f2, $f2, $f0
/* C38120 80241BF0 0C0372DF */  jal       func_800DCB7C
/* C38124 80241BF4 46201520 */   cvt.s.d  $f20, $f2
/* C38128 80241BF8 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* C3812C 80241BFC 46140000 */  add.s     $f0, $f0, $f20
/* C38130 80241C00 C622003C */  lwc1      $f2, 0x3c($s1)
/* C38134 80241C04 4600103C */  c.lt.s    $f2, $f0
/* C38138 80241C08 00000000 */  nop       
/* C3813C 80241C0C 45010028 */  bc1t      .L80241CB0
/* C38140 80241C10 00000000 */   nop      
/* C38144 80241C14 8E0200D0 */  lw        $v0, 0xd0($s0)
/* C38148 80241C18 C62C0038 */  lwc1      $f12, 0x38($s1)
/* C3814C 80241C1C C62E0040 */  lwc1      $f14, 0x40($s1)
/* C38150 80241C20 C44A0000 */  lwc1      $f10, ($v0)
/* C38154 80241C24 468052A0 */  cvt.s.w   $f10, $f10
/* C38158 80241C28 44065000 */  mfc1      $a2, $f10
/* C3815C 80241C2C C44A0008 */  lwc1      $f10, 8($v0)
/* C38160 80241C30 468052A0 */  cvt.s.w   $f10, $f10
/* C38164 80241C34 44075000 */  mfc1      $a3, $f10
/* C38168 80241C38 0C00A720 */  jal       atan2
/* C3816C 80241C3C 2410000A */   addiu    $s0, $zero, 0xa
/* C38170 80241C40 24040002 */  addiu     $a0, $zero, 2
/* C38174 80241C44 0220282D */  daddu     $a1, $s1, $zero
/* C38178 80241C48 0000302D */  daddu     $a2, $zero, $zero
/* C3817C 80241C4C C7A2002C */  lwc1      $f2, 0x2c($sp)
/* C38180 80241C50 862200A8 */  lh        $v0, 0xa8($s1)
/* C38184 80241C54 E620000C */  swc1      $f0, 0xc($s1)
/* C38188 80241C58 3C013F80 */  lui       $at, 0x3f80
/* C3818C 80241C5C 44810000 */  mtc1      $at, $f0
/* C38190 80241C60 3C014000 */  lui       $at, 0x4000
/* C38194 80241C64 44812000 */  mtc1      $at, $f4
/* C38198 80241C68 3C01C1A0 */  lui       $at, 0xc1a0
/* C3819C 80241C6C 44813000 */  mtc1      $at, $f6
/* C381A0 80241C70 44825000 */  mtc1      $v0, $f10
/* C381A4 80241C74 00000000 */  nop       
/* C381A8 80241C78 468052A0 */  cvt.s.w   $f10, $f10
/* C381AC 80241C7C 46141080 */  add.s     $f2, $f2, $f20
/* C381B0 80241C80 44075000 */  mfc1      $a3, $f10
/* C381B4 80241C84 27A20038 */  addiu     $v0, $sp, 0x38
/* C381B8 80241C88 E622003C */  swc1      $f2, 0x3c($s1)
/* C381BC 80241C8C E7A00010 */  swc1      $f0, 0x10($sp)
/* C381C0 80241C90 E7A40014 */  swc1      $f4, 0x14($sp)
/* C381C4 80241C94 E7A60018 */  swc1      $f6, 0x18($sp)
/* C381C8 80241C98 AFB0001C */  sw        $s0, 0x1c($sp)
/* C381CC 80241C9C 0C01BFA4 */  jal       fx_emote
/* C381D0 80241CA0 AFA20020 */   sw       $v0, 0x20($sp)
/* C381D4 80241CA4 24020012 */  addiu     $v0, $zero, 0x12
/* C381D8 80241CA8 A630008E */  sh        $s0, 0x8e($s1)
/* C381DC 80241CAC AE420070 */  sw        $v0, 0x70($s2)
.L80241CB0:
/* C381E0 80241CB0 8FBF004C */  lw        $ra, 0x4c($sp)
/* C381E4 80241CB4 8FB20048 */  lw        $s2, 0x48($sp)
/* C381E8 80241CB8 8FB10044 */  lw        $s1, 0x44($sp)
/* C381EC 80241CBC 8FB00040 */  lw        $s0, 0x40($sp)
/* C381F0 80241CC0 D7B40050 */  ldc1      $f20, 0x50($sp)
/* C381F4 80241CC4 03E00008 */  jr        $ra
/* C381F8 80241CC8 27BD0058 */   addiu    $sp, $sp, 0x58
