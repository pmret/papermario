.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240158_D95748
/* D95748 80240158 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* D9574C 8024015C AFB00040 */  sw        $s0, 0x40($sp)
/* D95750 80240160 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* D95754 80240164 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* D95758 80240168 AFB20048 */  sw        $s2, 0x48($sp)
/* D9575C 8024016C AFBF004C */  sw        $ra, 0x4c($sp)
/* D95760 80240170 AFB10044 */  sw        $s1, 0x44($sp)
/* D95764 80240174 8E020000 */  lw        $v0, ($s0)
/* D95768 80240178 821100BE */  lb        $s1, 0xbe($s0)
/* D9576C 8024017C 30420001 */  andi      $v0, $v0, 1
/* D95770 80240180 10400061 */  beqz      $v0, .L80240308
/* D95774 80240184 27B20020 */   addiu    $s2, $sp, 0x20
/* D95778 80240188 8E0400CC */  lw        $a0, 0xcc($s0)
/* D9577C 8024018C 0C044181 */  jal       get_shadow_by_index
/* D95780 80240190 00000000 */   nop      
/* D95784 80240194 0C048B77 */  jal       func_80122DDC
/* D95788 80240198 84440008 */   lh       $a0, 8($v0)
/* D9578C 8024019C 8C430000 */  lw        $v1, ($v0)
/* D95790 802401A0 34630200 */  ori       $v1, $v1, 0x200
/* D95794 802401A4 AC430000 */  sw        $v1, ($v0)
/* D95798 802401A8 8E050028 */  lw        $a1, 0x28($s0)
/* D9579C 802401AC 8E06002C */  lw        $a2, 0x2c($s0)
/* D957A0 802401B0 27A20030 */  addiu     $v0, $sp, 0x30
/* D957A4 802401B4 AFA20010 */  sw        $v0, 0x10($sp)
/* D957A8 802401B8 27A20034 */  addiu     $v0, $sp, 0x34
/* D957AC 802401BC AFA20014 */  sw        $v0, 0x14($sp)
/* D957B0 802401C0 C6000030 */  lwc1      $f0, 0x30($s0)
/* D957B4 802401C4 3C04800A */  lui       $a0, 0x800a
/* D957B8 802401C8 8484A634 */  lh        $a0, -0x59cc($a0)
/* D957BC 802401CC 46000007 */  neg.s     $f0, $f0
/* D957C0 802401D0 44070000 */  mfc1      $a3, $f0
/* D957C4 802401D4 27A20038 */  addiu     $v0, $sp, 0x38
/* D957C8 802401D8 0C00B94E */  jal       get_screen_coords
/* D957CC 802401DC AFA20018 */   sw       $v0, 0x18($sp)
/* D957D0 802401E0 8E0400A4 */  lw        $a0, 0xa4($s0)
/* D957D4 802401E4 0C090014 */  jal       func_80240050
/* D957D8 802401E8 00000000 */   nop      
/* D957DC 802401EC C6020080 */  lwc1      $f2, 0x80($s0)
/* D957E0 802401F0 3C014307 */  lui       $at, 0x4307
/* D957E4 802401F4 44810000 */  mtc1      $at, $f0
/* D957E8 802401F8 00000000 */  nop       
/* D957EC 802401FC 4602003C */  c.lt.s    $f0, $f2
/* D957F0 80240200 00000000 */  nop       
/* D957F4 80240204 4500000B */  bc1f      .L80240234
/* D957F8 80240208 24040002 */   addiu    $a0, $zero, 2
/* D957FC 8024020C 3C014361 */  lui       $at, 0x4361
/* D95800 80240210 44810000 */  mtc1      $at, $f0
/* D95804 80240214 00000000 */  nop       
/* D95808 80240218 4600103C */  c.lt.s    $f2, $f0
/* D9580C 8024021C 00000000 */  nop       
/* D95810 80240220 45000004 */  bc1f      .L80240234
/* D95814 80240224 00000000 */   nop      
/* D95818 80240228 0C090021 */  jal       func_80240084
/* D9581C 8024022C 0040202D */   daddu    $a0, $v0, $zero
/* D95820 80240230 24040002 */  addiu     $a0, $zero, 2
.L80240234:
/* D95824 80240234 3C063F80 */  lui       $a2, 0x3f80
/* D95828 80240238 0C0B76A3 */  jal       func_802DDA8C
/* D9582C 8024023C 0040282D */   daddu    $a1, $v0, $zero
/* D95830 80240240 8E020000 */  lw        $v0, ($s0)
/* D95834 80240244 3C030002 */  lui       $v1, 2
/* D95838 80240248 00431024 */  and       $v0, $v0, $v1
/* D9583C 8024024C 54400022 */  bnel      $v0, $zero, .L802402D8
/* D95840 80240250 24110011 */   addiu    $s1, $zero, 0x11
/* D95844 80240254 9203000E */  lbu       $v1, 0xe($s0)
/* D95848 80240258 3C02802E */  lui       $v0, 0x802e
/* D9584C 8024025C 90429D70 */  lbu       $v0, -0x6290($v0)
/* D95850 80240260 10620018 */  beq       $v1, $v0, .L802402C4
/* D95854 80240264 2C6200FE */   sltiu    $v0, $v1, 0xfe
/* D95858 80240268 1040000B */  beqz      $v0, .L80240298
/* D9585C 8024026C 24110011 */   addiu    $s1, $zero, 0x11
/* D95860 80240270 24040002 */  addiu     $a0, $zero, 2
/* D95864 80240274 2405FFFF */  addiu     $a1, $zero, -1
/* D95868 80240278 24060007 */  addiu     $a2, $zero, 7
/* D9586C 8024027C 0060102D */  daddu     $v0, $v1, $zero
/* D95870 80240280 0000382D */  daddu     $a3, $zero, $zero
/* D95874 80240284 AFA00010 */  sw        $zero, 0x10($sp)
/* D95878 80240288 AFA00014 */  sw        $zero, 0x14($sp)
/* D9587C 8024028C AFA0001C */  sw        $zero, 0x1c($sp)
/* D95880 80240290 080900AF */  j         .L802402BC
/* D95884 80240294 AFA20018 */   sw       $v0, 0x18($sp)
.L80240298:
/* D95888 80240298 2411000D */  addiu     $s1, $zero, 0xd
/* D9588C 8024029C 24040002 */  addiu     $a0, $zero, 2
/* D95890 802402A0 2405FFFF */  addiu     $a1, $zero, -1
/* D95894 802402A4 0000302D */  daddu     $a2, $zero, $zero
/* D95898 802402A8 00C0382D */  daddu     $a3, $a2, $zero
/* D9589C 802402AC AFA00010 */  sw        $zero, 0x10($sp)
/* D958A0 802402B0 AFA00014 */  sw        $zero, 0x14($sp)
/* D958A4 802402B4 AFA00018 */  sw        $zero, 0x18($sp)
/* D958A8 802402B8 AFA0001C */  sw        $zero, 0x1c($sp)
.L802402BC:
/* D958AC 802402BC 0C0B77B9 */  jal       func_802DDEE4
/* D958B0 802402C0 00000000 */   nop      
.L802402C4:
/* D958B4 802402C4 9202000E */  lbu       $v0, 0xe($s0)
/* D958B8 802402C8 3C01802E */  lui       $at, 0x802e
/* D958BC 802402CC A0229D70 */  sb        $v0, -0x6290($at)
/* D958C0 802402D0 080900B9 */  j         .L802402E4
/* D958C4 802402D4 0240202D */   daddu    $a0, $s2, $zero
.L802402D8:
/* D958C8 802402D8 3C01802E */  lui       $at, 0x802e
/* D958CC 802402DC A0209D70 */  sb        $zero, -0x6290($at)
/* D958D0 802402E0 0240202D */  daddu     $a0, $s2, $zero
.L802402E4:
/* D958D4 802402E4 AC910000 */  sw        $s1, ($a0)
/* D958D8 802402E8 AC900008 */  sw        $s0, 8($a0)
/* D958DC 802402EC 8FA20038 */  lw        $v0, 0x38($sp)
/* D958E0 802402F0 3C038024 */  lui       $v1, 0x8024
/* D958E4 802402F4 24630320 */  addiu     $v1, $v1, 0x320
/* D958E8 802402F8 AC83000C */  sw        $v1, 0xc($a0)
/* D958EC 802402FC 00021023 */  negu      $v0, $v0
/* D958F0 80240300 0C047644 */  jal       queue_render_task
/* D958F4 80240304 AC820004 */   sw       $v0, 4($a0)
.L80240308:
/* D958F8 80240308 8FBF004C */  lw        $ra, 0x4c($sp)
/* D958FC 8024030C 8FB20048 */  lw        $s2, 0x48($sp)
/* D95900 80240310 8FB10044 */  lw        $s1, 0x44($sp)
/* D95904 80240314 8FB00040 */  lw        $s0, 0x40($sp)
/* D95908 80240318 03E00008 */  jr        $ra
/* D9590C 8024031C 27BD0050 */   addiu    $sp, $sp, 0x50
