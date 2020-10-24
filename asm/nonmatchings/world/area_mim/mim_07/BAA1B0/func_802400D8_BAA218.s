.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400D8_BAA218
/* BAA218 802400D8 3C058024 */  lui       $a1, 0x8024
/* BAA21C 802400DC 24A51680 */  addiu     $a1, $a1, 0x1680
/* BAA220 802400E0 8CA30000 */  lw        $v1, ($a1)
/* BAA224 802400E4 24040002 */  addiu     $a0, $zero, 2
/* BAA228 802400E8 10640012 */  beq       $v1, $a0, .L80240134
/* BAA22C 802400EC 28620003 */   slti     $v0, $v1, 3
/* BAA230 802400F0 10400005 */  beqz      $v0, .L80240108
/* BAA234 802400F4 24020001 */   addiu    $v0, $zero, 1
/* BAA238 802400F8 1062000A */  beq       $v1, $v0, .L80240124
/* BAA23C 802400FC 3C02E300 */   lui      $v0, 0xe300
/* BAA240 80240100 08090071 */  j         .L802401C4
/* BAA244 80240104 34420A01 */   ori      $v0, $v0, 0xa01
.L80240108:
/* BAA248 80240108 24020003 */  addiu     $v0, $zero, 3
/* BAA24C 8024010C 10620019 */  beq       $v1, $v0, .L80240174
/* BAA250 80240110 24020004 */   addiu    $v0, $zero, 4
/* BAA254 80240114 10620021 */  beq       $v1, $v0, .L8024019C
/* BAA258 80240118 3C02E300 */   lui      $v0, 0xe300
/* BAA25C 8024011C 08090071 */  j         .L802401C4
/* BAA260 80240120 34420A01 */   ori      $v0, $v0, 0xa01
.L80240124:
/* BAA264 80240124 3C018024 */  lui       $at, 0x8024
/* BAA268 80240128 AC201688 */  sw        $zero, 0x1688($at)
/* BAA26C 8024012C 0809006F */  j         .L802401BC
/* BAA270 80240130 ACA40000 */   sw       $a0, ($a1)
.L80240134:
/* BAA274 80240134 3C038024 */  lui       $v1, 0x8024
/* BAA278 80240138 24631688 */  addiu     $v1, $v1, 0x1688
/* BAA27C 8024013C 8C620000 */  lw        $v0, ($v1)
/* BAA280 80240140 2442000A */  addiu     $v0, $v0, 0xa
/* BAA284 80240144 AC620000 */  sw        $v0, ($v1)
/* BAA288 80240148 28420100 */  slti      $v0, $v0, 0x100
/* BAA28C 8024014C 1440001C */  bnez      $v0, .L802401C0
/* BAA290 80240150 3C02E300 */   lui      $v0, 0xe300
/* BAA294 80240154 240200FF */  addiu     $v0, $zero, 0xff
/* BAA298 80240158 AC620000 */  sw        $v0, ($v1)
/* BAA29C 8024015C 24020032 */  addiu     $v0, $zero, 0x32
/* BAA2A0 80240160 3C018024 */  lui       $at, 0x8024
/* BAA2A4 80240164 AC221684 */  sw        $v0, 0x1684($at)
/* BAA2A8 80240168 24020003 */  addiu     $v0, $zero, 3
/* BAA2AC 8024016C 0809006F */  j         .L802401BC
/* BAA2B0 80240170 ACA20000 */   sw       $v0, ($a1)
.L80240174:
/* BAA2B4 80240174 3C038024 */  lui       $v1, 0x8024
/* BAA2B8 80240178 24631684 */  addiu     $v1, $v1, 0x1684
/* BAA2BC 8024017C 8C620000 */  lw        $v0, ($v1)
/* BAA2C0 80240180 2442FFFF */  addiu     $v0, $v0, -1
/* BAA2C4 80240184 0441000D */  bgez      $v0, .L802401BC
/* BAA2C8 80240188 AC620000 */   sw       $v0, ($v1)
/* BAA2CC 8024018C 24020004 */  addiu     $v0, $zero, 4
/* BAA2D0 80240190 AC600000 */  sw        $zero, ($v1)
/* BAA2D4 80240194 0809006F */  j         .L802401BC
/* BAA2D8 80240198 ACA20000 */   sw       $v0, ($a1)
.L8024019C:
/* BAA2DC 8024019C 3C038024 */  lui       $v1, 0x8024
/* BAA2E0 802401A0 24631688 */  addiu     $v1, $v1, 0x1688
/* BAA2E4 802401A4 8C620000 */  lw        $v0, ($v1)
/* BAA2E8 802401A8 2442FFF9 */  addiu     $v0, $v0, -7
/* BAA2EC 802401AC 04410003 */  bgez      $v0, .L802401BC
/* BAA2F0 802401B0 AC620000 */   sw       $v0, ($v1)
/* BAA2F4 802401B4 AC600000 */  sw        $zero, ($v1)
/* BAA2F8 802401B8 ACA00000 */  sw        $zero, ($a1)
.L802401BC:
/* BAA2FC 802401BC 3C02E300 */  lui       $v0, 0xe300
.L802401C0:
/* BAA300 802401C0 34420A01 */  ori       $v0, $v0, 0xa01
.L802401C4:
/* BAA304 802401C4 3C06FC12 */  lui       $a2, 0xfc12
/* BAA308 802401C8 34C6160A */  ori       $a2, $a2, 0x160a
/* BAA30C 802401CC 3C08E200 */  lui       $t0, 0xe200
/* BAA310 802401D0 3508001C */  ori       $t0, $t0, 0x1c
/* BAA314 802401D4 3C07C810 */  lui       $a3, 0xc810
/* BAA318 802401D8 3C05800A */  lui       $a1, 0x800a
/* BAA31C 802401DC 24A5A66C */  addiu     $a1, $a1, -0x5994
/* BAA320 802401E0 8CA30000 */  lw        $v1, ($a1)
/* BAA324 802401E4 34E74DD8 */  ori       $a3, $a3, 0x4dd8
/* BAA328 802401E8 0060202D */  daddu     $a0, $v1, $zero
/* BAA32C 802401EC 24630008 */  addiu     $v1, $v1, 8
/* BAA330 802401F0 ACA30000 */  sw        $v1, ($a1)
/* BAA334 802401F4 AC820000 */  sw        $v0, ($a0)
/* BAA338 802401F8 3C020010 */  lui       $v0, 0x10
/* BAA33C 802401FC AC820004 */  sw        $v0, 4($a0)
/* BAA340 80240200 24620008 */  addiu     $v0, $v1, 8
/* BAA344 80240204 ACA20000 */  sw        $v0, ($a1)
/* BAA348 80240208 3C048024 */  lui       $a0, 0x8024
/* BAA34C 8024020C 9084168B */  lbu       $a0, 0x168b($a0)
/* BAA350 80240210 3C02FA00 */  lui       $v0, 0xfa00
/* BAA354 80240214 AC620000 */  sw        $v0, ($v1)
/* BAA358 80240218 24620010 */  addiu     $v0, $v1, 0x10
/* BAA35C 8024021C AC640004 */  sw        $a0, 4($v1)
/* BAA360 80240220 ACA20000 */  sw        $v0, ($a1)
/* BAA364 80240224 2402FFF8 */  addiu     $v0, $zero, -8
/* BAA368 80240228 AC62000C */  sw        $v0, 0xc($v1)
/* BAA36C 8024022C 24620018 */  addiu     $v0, $v1, 0x18
/* BAA370 80240230 AC660008 */  sw        $a2, 8($v1)
/* BAA374 80240234 ACA20000 */  sw        $v0, ($a1)
/* BAA378 80240238 AC680010 */  sw        $t0, 0x10($v1)
/* BAA37C 8024023C 03E00008 */  jr        $ra
/* BAA380 80240240 AC670014 */   sw       $a3, 0x14($v1)
