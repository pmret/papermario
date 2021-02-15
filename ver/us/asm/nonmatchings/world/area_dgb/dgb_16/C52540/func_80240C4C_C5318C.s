.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C4C_C5318C
/* C5318C 80240C4C 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* C53190 80240C50 AFB3002C */  sw        $s3, 0x2c($sp)
/* C53194 80240C54 0080982D */  daddu     $s3, $a0, $zero
/* C53198 80240C58 AFBF0030 */  sw        $ra, 0x30($sp)
/* C5319C 80240C5C AFB20028 */  sw        $s2, 0x28($sp)
/* C531A0 80240C60 AFB10024 */  sw        $s1, 0x24($sp)
/* C531A4 80240C64 AFB00020 */  sw        $s0, 0x20($sp)
/* C531A8 80240C68 8E720148 */  lw        $s2, 0x148($s3)
/* C531AC 80240C6C 00A0882D */  daddu     $s1, $a1, $zero
/* C531B0 80240C70 86440008 */  lh        $a0, 8($s2)
/* C531B4 80240C74 0C00EABB */  jal       get_npc_unsafe
/* C531B8 80240C78 00C0802D */   daddu    $s0, $a2, $zero
/* C531BC 80240C7C 0200202D */  daddu     $a0, $s0, $zero
/* C531C0 80240C80 0240282D */  daddu     $a1, $s2, $zero
/* C531C4 80240C84 AFA00010 */  sw        $zero, 0x10($sp)
/* C531C8 80240C88 8E260024 */  lw        $a2, 0x24($s1)
/* C531CC 80240C8C 8E270028 */  lw        $a3, 0x28($s1)
/* C531D0 80240C90 0C01242D */  jal       func_800490B4
/* C531D4 80240C94 0040802D */   daddu    $s0, $v0, $zero
/* C531D8 80240C98 1040000C */  beqz      $v0, .L80240CCC
/* C531DC 80240C9C 00000000 */   nop
/* C531E0 80240CA0 C60C0038 */  lwc1      $f12, 0x38($s0)
/* C531E4 80240CA4 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C531E8 80240CA8 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C531EC 80240CAC C60E0040 */  lwc1      $f14, 0x40($s0)
/* C531F0 80240CB0 8C460028 */  lw        $a2, 0x28($v0)
/* C531F4 80240CB4 0C00A720 */  jal       atan2
/* C531F8 80240CB8 8C470030 */   lw       $a3, 0x30($v0)
/* C531FC 80240CBC 2402000C */  addiu     $v0, $zero, 0xc
/* C53200 80240CC0 E600000C */  swc1      $f0, 0xc($s0)
/* C53204 80240CC4 0809036A */  j         .L80240DA8
/* C53208 80240CC8 AE620070 */   sw       $v0, 0x70($s3)
.L80240CCC:
/* C5320C 80240CCC C60C0038 */  lwc1      $f12, 0x38($s0)
/* C53210 80240CD0 8E4200D0 */  lw        $v0, 0xd0($s2)
/* C53214 80240CD4 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C53218 80240CD8 C4440000 */  lwc1      $f4, ($v0)
/* C5321C 80240CDC 46802120 */  cvt.s.w   $f4, $f4
/* C53220 80240CE0 44062000 */  mfc1      $a2, $f4
/* C53224 80240CE4 C4440008 */  lwc1      $f4, 8($v0)
/* C53228 80240CE8 46802120 */  cvt.s.w   $f4, $f4
/* C5322C 80240CEC 44072000 */  mfc1      $a3, $f4
/* C53230 80240CF0 0C00A7B5 */  jal       dist2D
/* C53234 80240CF4 00000000 */   nop
/* C53238 80240CF8 C6020018 */  lwc1      $f2, 0x18($s0)
/* C5323C 80240CFC 4602003E */  c.le.s    $f0, $f2
/* C53240 80240D00 00000000 */  nop
/* C53244 80240D04 4500000B */  bc1f      .L80240D34
/* C53248 80240D08 00000000 */   nop
/* C5324C 80240D0C 8E4200CC */  lw        $v0, 0xcc($s2)
/* C53250 80240D10 8C430000 */  lw        $v1, ($v0)
/* C53254 80240D14 2402000F */  addiu     $v0, $zero, 0xf
/* C53258 80240D18 A602008E */  sh        $v0, 0x8e($s0)
/* C5325C 80240D1C 24020032 */  addiu     $v0, $zero, 0x32
/* C53260 80240D20 AE030028 */  sw        $v1, 0x28($s0)
/* C53264 80240D24 AE420088 */  sw        $v0, 0x88($s2)
/* C53268 80240D28 24020003 */  addiu     $v0, $zero, 3
/* C5326C 80240D2C 0809036A */  j         .L80240DA8
/* C53270 80240D30 AE620070 */   sw       $v0, 0x70($s3)
.L80240D34:
/* C53274 80240D34 8602008C */  lh        $v0, 0x8c($s0)
/* C53278 80240D38 1440001B */  bnez      $v0, .L80240DA8
/* C5327C 80240D3C 0200202D */   daddu    $a0, $s0, $zero
/* C53280 80240D40 27A60018 */  addiu     $a2, $sp, 0x18
/* C53284 80240D44 3C0540A0 */  lui       $a1, 0x40a0
/* C53288 80240D48 C600000C */  lwc1      $f0, 0xc($s0)
/* C5328C 80240D4C 0000382D */  daddu     $a3, $zero, $zero
/* C53290 80240D50 E7A00018 */  swc1      $f0, 0x18($sp)
/* C53294 80240D54 AFA00010 */  sw        $zero, 0x10($sp)
/* C53298 80240D58 0C0129E1 */  jal       func_8004A784
/* C5329C 80240D5C AFA00014 */   sw       $zero, 0x14($sp)
/* C532A0 80240D60 C7A00018 */  lwc1      $f0, 0x18($sp)
/* C532A4 80240D64 C60C0038 */  lwc1      $f12, 0x38($s0)
/* C532A8 80240D68 E600000C */  swc1      $f0, 0xc($s0)
/* C532AC 80240D6C 8E4200D0 */  lw        $v0, 0xd0($s2)
/* C532B0 80240D70 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C532B4 80240D74 C4440000 */  lwc1      $f4, ($v0)
/* C532B8 80240D78 46802120 */  cvt.s.w   $f4, $f4
/* C532BC 80240D7C 44062000 */  mfc1      $a2, $f4
/* C532C0 80240D80 C4440008 */  lwc1      $f4, 8($v0)
/* C532C4 80240D84 46802120 */  cvt.s.w   $f4, $f4
/* C532C8 80240D88 44072000 */  mfc1      $a3, $f4
/* C532CC 80240D8C 0C00A720 */  jal       atan2
/* C532D0 80240D90 00000000 */   nop
/* C532D4 80240D94 8E050018 */  lw        $a1, 0x18($s0)
/* C532D8 80240D98 44060000 */  mfc1      $a2, $f0
/* C532DC 80240D9C 0200202D */  daddu     $a0, $s0, $zero
/* C532E0 80240DA0 0C00EA95 */  jal       npc_move_heading
/* C532E4 80240DA4 AC86000C */   sw       $a2, 0xc($a0)
.L80240DA8:
/* C532E8 80240DA8 8FBF0030 */  lw        $ra, 0x30($sp)
/* C532EC 80240DAC 8FB3002C */  lw        $s3, 0x2c($sp)
/* C532F0 80240DB0 8FB20028 */  lw        $s2, 0x28($sp)
/* C532F4 80240DB4 8FB10024 */  lw        $s1, 0x24($sp)
/* C532F8 80240DB8 8FB00020 */  lw        $s0, 0x20($sp)
/* C532FC 80240DBC 03E00008 */  jr        $ra
/* C53300 80240DC0 27BD0038 */   addiu    $sp, $sp, 0x38
