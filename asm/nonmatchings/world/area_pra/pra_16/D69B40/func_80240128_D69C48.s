.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240128_D69C48
/* D69C48 80240128 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* D69C4C 8024012C AFB00040 */  sw        $s0, 0x40($sp)
/* D69C50 80240130 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* D69C54 80240134 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* D69C58 80240138 AFB20048 */  sw        $s2, 0x48($sp)
/* D69C5C 8024013C AFBF004C */  sw        $ra, 0x4c($sp)
/* D69C60 80240140 AFB10044 */  sw        $s1, 0x44($sp)
/* D69C64 80240144 8E020000 */  lw        $v0, ($s0)
/* D69C68 80240148 821100BE */  lb        $s1, 0xbe($s0)
/* D69C6C 8024014C 30420001 */  andi      $v0, $v0, 1
/* D69C70 80240150 10400061 */  beqz      $v0, .L802402D8
/* D69C74 80240154 27B20020 */   addiu    $s2, $sp, 0x20
/* D69C78 80240158 8E0400CC */  lw        $a0, 0xcc($s0)
/* D69C7C 8024015C 0C044181 */  jal       get_shadow_by_index
/* D69C80 80240160 00000000 */   nop      
/* D69C84 80240164 0C048B77 */  jal       func_80122DDC
/* D69C88 80240168 84440008 */   lh       $a0, 8($v0)
/* D69C8C 8024016C 8C430000 */  lw        $v1, ($v0)
/* D69C90 80240170 34630200 */  ori       $v1, $v1, 0x200
/* D69C94 80240174 AC430000 */  sw        $v1, ($v0)
/* D69C98 80240178 8E050028 */  lw        $a1, 0x28($s0)
/* D69C9C 8024017C 8E06002C */  lw        $a2, 0x2c($s0)
/* D69CA0 80240180 27A20030 */  addiu     $v0, $sp, 0x30
/* D69CA4 80240184 AFA20010 */  sw        $v0, 0x10($sp)
/* D69CA8 80240188 27A20034 */  addiu     $v0, $sp, 0x34
/* D69CAC 8024018C AFA20014 */  sw        $v0, 0x14($sp)
/* D69CB0 80240190 C6000030 */  lwc1      $f0, 0x30($s0)
/* D69CB4 80240194 3C04800A */  lui       $a0, %hi(D_8009A634)
/* D69CB8 80240198 8484A634 */  lh        $a0, %lo(D_8009A634)($a0)
/* D69CBC 8024019C 46000007 */  neg.s     $f0, $f0
/* D69CC0 802401A0 44070000 */  mfc1      $a3, $f0
/* D69CC4 802401A4 27A20038 */  addiu     $v0, $sp, 0x38
/* D69CC8 802401A8 0C00B94E */  jal       get_screen_coords
/* D69CCC 802401AC AFA20018 */   sw       $v0, 0x18($sp)
/* D69CD0 802401B0 8E0400A4 */  lw        $a0, 0xa4($s0)
/* D69CD4 802401B4 0C090008 */  jal       func_80240020_D69B40
/* D69CD8 802401B8 00000000 */   nop      
/* D69CDC 802401BC C6020080 */  lwc1      $f2, 0x80($s0)
/* D69CE0 802401C0 3C014307 */  lui       $at, 0x4307
/* D69CE4 802401C4 44810000 */  mtc1      $at, $f0
/* D69CE8 802401C8 00000000 */  nop       
/* D69CEC 802401CC 4602003C */  c.lt.s    $f0, $f2
/* D69CF0 802401D0 00000000 */  nop       
/* D69CF4 802401D4 4500000B */  bc1f      .L80240204
/* D69CF8 802401D8 24040002 */   addiu    $a0, $zero, 2
/* D69CFC 802401DC 3C014361 */  lui       $at, 0x4361
/* D69D00 802401E0 44810000 */  mtc1      $at, $f0
/* D69D04 802401E4 00000000 */  nop       
/* D69D08 802401E8 4600103C */  c.lt.s    $f2, $f0
/* D69D0C 802401EC 00000000 */  nop       
/* D69D10 802401F0 45000004 */  bc1f      .L80240204
/* D69D14 802401F4 00000000 */   nop      
/* D69D18 802401F8 0C090015 */  jal       func_80240054_D69B74
/* D69D1C 802401FC 0040202D */   daddu    $a0, $v0, $zero
/* D69D20 80240200 24040002 */  addiu     $a0, $zero, 2
.L80240204:
/* D69D24 80240204 3C063F80 */  lui       $a2, 0x3f80
/* D69D28 80240208 0C0B76A3 */  jal       func_802DDA8C
/* D69D2C 8024020C 0040282D */   daddu    $a1, $v0, $zero
/* D69D30 80240210 8E020000 */  lw        $v0, ($s0)
/* D69D34 80240214 3C030002 */  lui       $v1, 2
/* D69D38 80240218 00431024 */  and       $v0, $v0, $v1
/* D69D3C 8024021C 54400022 */  bnel      $v0, $zero, .L802402A8
/* D69D40 80240220 24110011 */   addiu    $s1, $zero, 0x11
/* D69D44 80240224 9203000E */  lbu       $v1, 0xe($s0)
/* D69D48 80240228 3C02802E */  lui       $v0, %hi(D_802D9D70)
/* D69D4C 8024022C 90429D70 */  lbu       $v0, %lo(D_802D9D70)($v0)
/* D69D50 80240230 10620018 */  beq       $v1, $v0, .L80240294
/* D69D54 80240234 2C6200FE */   sltiu    $v0, $v1, 0xfe
/* D69D58 80240238 1040000B */  beqz      $v0, .L80240268
/* D69D5C 8024023C 24110011 */   addiu    $s1, $zero, 0x11
/* D69D60 80240240 24040002 */  addiu     $a0, $zero, 2
/* D69D64 80240244 2405FFFF */  addiu     $a1, $zero, -1
/* D69D68 80240248 24060007 */  addiu     $a2, $zero, 7
/* D69D6C 8024024C 0060102D */  daddu     $v0, $v1, $zero
/* D69D70 80240250 0000382D */  daddu     $a3, $zero, $zero
/* D69D74 80240254 AFA00010 */  sw        $zero, 0x10($sp)
/* D69D78 80240258 AFA00014 */  sw        $zero, 0x14($sp)
/* D69D7C 8024025C AFA0001C */  sw        $zero, 0x1c($sp)
/* D69D80 80240260 080900A3 */  j         .L8024028C
/* D69D84 80240264 AFA20018 */   sw       $v0, 0x18($sp)
.L80240268:
/* D69D88 80240268 2411000D */  addiu     $s1, $zero, 0xd
/* D69D8C 8024026C 24040002 */  addiu     $a0, $zero, 2
/* D69D90 80240270 2405FFFF */  addiu     $a1, $zero, -1
/* D69D94 80240274 0000302D */  daddu     $a2, $zero, $zero
/* D69D98 80240278 00C0382D */  daddu     $a3, $a2, $zero
/* D69D9C 8024027C AFA00010 */  sw        $zero, 0x10($sp)
/* D69DA0 80240280 AFA00014 */  sw        $zero, 0x14($sp)
/* D69DA4 80240284 AFA00018 */  sw        $zero, 0x18($sp)
/* D69DA8 80240288 AFA0001C */  sw        $zero, 0x1c($sp)
.L8024028C:
/* D69DAC 8024028C 0C0B77B9 */  jal       func_802DDEE4
/* D69DB0 80240290 00000000 */   nop      
.L80240294:
/* D69DB4 80240294 9202000E */  lbu       $v0, 0xe($s0)
/* D69DB8 80240298 3C01802E */  lui       $at, %hi(D_802D9D70)
/* D69DBC 8024029C A0229D70 */  sb        $v0, %lo(D_802D9D70)($at)
/* D69DC0 802402A0 080900AD */  j         .L802402B4
/* D69DC4 802402A4 0240202D */   daddu    $a0, $s2, $zero
.L802402A8:
/* D69DC8 802402A8 3C01802E */  lui       $at, %hi(D_802D9D70)
/* D69DCC 802402AC A0209D70 */  sb        $zero, %lo(D_802D9D70)($at)
/* D69DD0 802402B0 0240202D */  daddu     $a0, $s2, $zero
.L802402B4:
/* D69DD4 802402B4 AC910000 */  sw        $s1, ($a0)
/* D69DD8 802402B8 AC900008 */  sw        $s0, 8($a0)
/* D69DDC 802402BC 8FA20038 */  lw        $v0, 0x38($sp)
/* D69DE0 802402C0 3C038024 */  lui       $v1, %hi(func_802402F0_D69D08)
/* D69DE4 802402C4 246302F0 */  addiu     $v1, $v1, %lo(func_802402F0_D69D08)
/* D69DE8 802402C8 AC83000C */  sw        $v1, 0xc($a0)
/* D69DEC 802402CC 00021023 */  negu      $v0, $v0
/* D69DF0 802402D0 0C047644 */  jal       queue_render_task
/* D69DF4 802402D4 AC820004 */   sw       $v0, 4($a0)
.L802402D8:
/* D69DF8 802402D8 8FBF004C */  lw        $ra, 0x4c($sp)
/* D69DFC 802402DC 8FB20048 */  lw        $s2, 0x48($sp)
/* D69E00 802402E0 8FB10044 */  lw        $s1, 0x44($sp)
/* D69E04 802402E4 8FB00040 */  lw        $s0, 0x40($sp)
/* D69E08 802402E8 03E00008 */  jr        $ra
/* D69E0C 802402EC 27BD0050 */   addiu    $sp, $sp, 0x50
