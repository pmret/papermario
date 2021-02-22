.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401F0_A60BC0
/* A60BC0 802401F0 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* A60BC4 802401F4 AFB20038 */  sw        $s2, 0x38($sp)
/* A60BC8 802401F8 0080902D */  daddu     $s2, $a0, $zero
/* A60BCC 802401FC AFB00030 */  sw        $s0, 0x30($sp)
/* A60BD0 80240200 AFBF003C */  sw        $ra, 0x3c($sp)
/* A60BD4 80240204 AFB10034 */  sw        $s1, 0x34($sp)
/* A60BD8 80240208 F7B60048 */  sdc1      $f22, 0x48($sp)
/* A60BDC 8024020C F7B40040 */  sdc1      $f20, 0x40($sp)
/* A60BE0 80240210 8E510148 */  lw        $s1, 0x148($s2)
/* A60BE4 80240214 4485A000 */  mtc1      $a1, $f20
/* A60BE8 80240218 86240008 */  lh        $a0, 8($s1)
/* A60BEC 8024021C 4486B000 */  mtc1      $a2, $f22
/* A60BF0 80240220 0C00EABB */  jal       get_npc_unsafe
/* A60BF4 80240224 00E0802D */   daddu    $s0, $a3, $zero
/* A60BF8 80240228 0200202D */  daddu     $a0, $s0, $zero
/* A60BFC 8024022C 0220282D */  daddu     $a1, $s1, $zero
/* A60C00 80240230 24030001 */  addiu     $v1, $zero, 1
/* A60C04 80240234 4406A000 */  mfc1      $a2, $f20
/* A60C08 80240238 4407B000 */  mfc1      $a3, $f22
/* A60C0C 8024023C 0040802D */  daddu     $s0, $v0, $zero
/* A60C10 80240240 0C01242D */  jal       func_800490B4
/* A60C14 80240244 AFA30010 */   sw       $v1, 0x10($sp)
/* A60C18 80240248 1440001D */  bnez      $v0, .L802402C0
/* A60C1C 8024024C 24040002 */   addiu    $a0, $zero, 2
/* A60C20 80240250 0200282D */  daddu     $a1, $s0, $zero
/* A60C24 80240254 0000302D */  daddu     $a2, $zero, $zero
/* A60C28 80240258 860300A8 */  lh        $v1, 0xa8($s0)
/* A60C2C 8024025C 3C013F80 */  lui       $at, 0x3f80
/* A60C30 80240260 44810000 */  mtc1      $at, $f0
/* A60C34 80240264 3C014000 */  lui       $at, 0x4000
/* A60C38 80240268 44811000 */  mtc1      $at, $f2
/* A60C3C 8024026C 3C01C1A0 */  lui       $at, 0xc1a0
/* A60C40 80240270 44812000 */  mtc1      $at, $f4
/* A60C44 80240274 2402000F */  addiu     $v0, $zero, 0xf
/* A60C48 80240278 AFA2001C */  sw        $v0, 0x1c($sp)
/* A60C4C 8024027C 44833000 */  mtc1      $v1, $f6
/* A60C50 80240280 00000000 */  nop
/* A60C54 80240284 468031A0 */  cvt.s.w   $f6, $f6
/* A60C58 80240288 44073000 */  mfc1      $a3, $f6
/* A60C5C 8024028C 27A20028 */  addiu     $v0, $sp, 0x28
/* A60C60 80240290 AFA20020 */  sw        $v0, 0x20($sp)
/* A60C64 80240294 E7A00010 */  swc1      $f0, 0x10($sp)
/* A60C68 80240298 E7A20014 */  swc1      $f2, 0x14($sp)
/* A60C6C 8024029C 0C01BFA4 */  jal       fx_emote
/* A60C70 802402A0 E7A40018 */   swc1     $f4, 0x18($sp)
/* A60C74 802402A4 8E2200CC */  lw        $v0, 0xcc($s1)
/* A60C78 802402A8 8C430000 */  lw        $v1, ($v0)
/* A60C7C 802402AC 24020014 */  addiu     $v0, $zero, 0x14
/* A60C80 802402B0 A602008E */  sh        $v0, 0x8e($s0)
/* A60C84 802402B4 24020021 */  addiu     $v0, $zero, 0x21
/* A60C88 802402B8 080900C4 */  j         .L80240310
/* A60C8C 802402BC AE030028 */   sw       $v1, 0x28($s0)
.L802402C0:
/* A60C90 802402C0 0C090000 */  jal       func_80240000_A609D0
/* A60C94 802402C4 0240202D */   daddu    $a0, $s2, $zero
/* A60C98 802402C8 0040202D */  daddu     $a0, $v0, $zero
/* A60C9C 802402CC 2402FFFF */  addiu     $v0, $zero, -1
/* A60CA0 802402D0 10820010 */  beq       $a0, $v0, .L80240314
/* A60CA4 802402D4 00000000 */   nop
/* A60CA8 802402D8 0C00FB3A */  jal       get_enemy
/* A60CAC 802402DC 00000000 */   nop
/* A60CB0 802402E0 8C42006C */  lw        $v0, 0x6c($v0)
/* A60CB4 802402E4 1440000B */  bnez      $v0, .L80240314
/* A60CB8 802402E8 00000000 */   nop
/* A60CBC 802402EC 8602008C */  lh        $v0, 0x8c($s0)
/* A60CC0 802402F0 14400008 */  bnez      $v0, .L80240314
/* A60CC4 802402F4 00000000 */   nop
/* A60CC8 802402F8 8E2200CC */  lw        $v0, 0xcc($s1)
/* A60CCC 802402FC 8C420020 */  lw        $v0, 0x20($v0)
/* A60CD0 80240300 AE020028 */  sw        $v0, 0x28($s0)
/* A60CD4 80240304 96220072 */  lhu       $v0, 0x72($s1)
/* A60CD8 80240308 A602008E */  sh        $v0, 0x8e($s0)
/* A60CDC 8024030C 2402001E */  addiu     $v0, $zero, 0x1e
.L80240310:
/* A60CE0 80240310 AE420070 */  sw        $v0, 0x70($s2)
.L80240314:
/* A60CE4 80240314 8FBF003C */  lw        $ra, 0x3c($sp)
/* A60CE8 80240318 8FB20038 */  lw        $s2, 0x38($sp)
/* A60CEC 8024031C 8FB10034 */  lw        $s1, 0x34($sp)
/* A60CF0 80240320 8FB00030 */  lw        $s0, 0x30($sp)
/* A60CF4 80240324 D7B60048 */  ldc1      $f22, 0x48($sp)
/* A60CF8 80240328 D7B40040 */  ldc1      $f20, 0x40($sp)
/* A60CFC 8024032C 03E00008 */  jr        $ra
/* A60D00 80240330 27BD0050 */   addiu    $sp, $sp, 0x50
