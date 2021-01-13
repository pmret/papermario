.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024019C_BF493C
/* BF493C 8024019C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* BF4940 802401A0 3C048024 */  lui       $a0, %hi(D_80241188)
/* BF4944 802401A4 24841188 */  addiu     $a0, $a0, %lo(D_80241188)
/* BF4948 802401A8 AFBF0018 */  sw        $ra, 0x18($sp)
/* BF494C 802401AC AFB10014 */  sw        $s1, 0x14($sp)
/* BF4950 802401B0 AFB00010 */  sw        $s0, 0x10($sp)
/* BF4954 802401B4 F7B40020 */  sdc1      $f20, 0x20($sp)
/* BF4958 802401B8 8C830000 */  lw        $v1, ($a0)
/* BF495C 802401BC 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* BF4960 802401C0 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* BF4964 802401C4 28620003 */  slti      $v0, $v1, 3
/* BF4968 802401C8 50400007 */  beql      $v0, $zero, .L802401E8
/* BF496C 802401CC 24020003 */   addiu    $v0, $zero, 3
/* BF4970 802401D0 1C60000C */  bgtz      $v1, .L80240204
/* BF4974 802401D4 24620001 */   addiu    $v0, $v1, 1
/* BF4978 802401D8 10600007 */  beqz      $v1, .L802401F8
/* BF497C 802401DC 0000102D */   daddu    $v0, $zero, $zero
/* BF4980 802401E0 0809009D */  j         .L80240274
/* BF4984 802401E4 00000000 */   nop
.L802401E8:
/* BF4988 802401E8 10620008 */  beq       $v1, $v0, .L8024020C
/* BF498C 802401EC 0000102D */   daddu    $v0, $zero, $zero
/* BF4990 802401F0 0809009D */  j         .L80240274
/* BF4994 802401F4 00000000 */   nop
.L802401F8:
/* BF4998 802401F8 24020001 */  addiu     $v0, $zero, 1
/* BF499C 802401FC 0809009C */  j         .L80240270
/* BF49A0 80240200 AC820000 */   sw       $v0, ($a0)
.L80240204:
/* BF49A4 80240204 0809009C */  j         .L80240270
/* BF49A8 80240208 AC820000 */   sw       $v0, ($a0)
.L8024020C:
/* BF49AC 8024020C 3C108011 */  lui       $s0, %hi(D_8010C930)
/* BF49B0 80240210 2610C930 */  addiu     $s0, $s0, %lo(D_8010C930)
/* BF49B4 80240214 0C03BD17 */  jal       clear_partner_move_history
/* BF49B8 80240218 8E040000 */   lw       $a0, ($s0)
/* BF49BC 8024021C C6200028 */  lwc1      $f0, 0x28($s1)
/* BF49C0 80240220 C6220030 */  lwc1      $f2, 0x30($s1)
/* BF49C4 80240224 4600010D */  trunc.w.s $f4, $f0
/* BF49C8 80240228 44042000 */  mfc1      $a0, $f4
/* BF49CC 8024022C 4600110D */  trunc.w.s $f4, $f2
/* BF49D0 80240230 44052000 */  mfc1      $a1, $f4
/* BF49D4 80240234 0C03BCF0 */  jal       func_800EF3C0
/* BF49D8 80240238 00000000 */   nop
/* BF49DC 8024023C 0C03BCF5 */  jal       func_800EF3D4
/* BF49E0 80240240 0000202D */   daddu    $a0, $zero, $zero
/* BF49E4 80240244 3C0142B4 */  lui       $at, 0x42b4
/* BF49E8 80240248 4481A000 */  mtc1      $at, $f20
/* BF49EC 8024024C 8E040000 */  lw        $a0, ($s0)
/* BF49F0 80240250 4405A000 */  mfc1      $a1, $f20
/* BF49F4 80240254 0C00ECD0 */  jal       set_npc_yaw
/* BF49F8 80240258 00000000 */   nop
/* BF49FC 8024025C 24020002 */  addiu     $v0, $zero, 2
/* BF4A00 80240260 E6340080 */  swc1      $f20, 0x80($s1)
/* BF4A04 80240264 E6340084 */  swc1      $f20, 0x84($s1)
/* BF4A08 80240268 0809009D */  j         .L80240274
/* BF4A0C 8024026C AE2000A8 */   sw       $zero, 0xa8($s1)
.L80240270:
/* BF4A10 80240270 0000102D */  daddu     $v0, $zero, $zero
.L80240274:
/* BF4A14 80240274 8FBF0018 */  lw        $ra, 0x18($sp)
/* BF4A18 80240278 8FB10014 */  lw        $s1, 0x14($sp)
/* BF4A1C 8024027C 8FB00010 */  lw        $s0, 0x10($sp)
/* BF4A20 80240280 D7B40020 */  ldc1      $f20, 0x20($sp)
/* BF4A24 80240284 03E00008 */  jr        $ra
/* BF4A28 80240288 27BD0028 */   addiu    $sp, $sp, 0x28
/* BF4A2C 8024028C 00000000 */  nop
