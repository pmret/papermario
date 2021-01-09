.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240070_B9D9D0
/* B9D9D0 80240070 3C058024 */  lui       $a1, %hi(func_80241530_8ED350)
/* B9D9D4 80240074 24A51530 */  addiu     $a1, $a1, %lo(func_80241530_8ED350)
/* B9D9D8 80240078 8CA30000 */  lw        $v1, ($a1)
/* B9D9DC 8024007C 24040002 */  addiu     $a0, $zero, 2
/* B9D9E0 80240080 10640012 */  beq       $v1, $a0, .L802400CC
/* B9D9E4 80240084 28620003 */   slti     $v0, $v1, 3
/* B9D9E8 80240088 10400005 */  beqz      $v0, .L802400A0
/* B9D9EC 8024008C 24020001 */   addiu    $v0, $zero, 1
/* B9D9F0 80240090 1062000A */  beq       $v1, $v0, .L802400BC
/* B9D9F4 80240094 3C02E300 */   lui      $v0, 0xe300
/* B9D9F8 80240098 08090057 */  j         .L8024015C
/* B9D9FC 8024009C 34420A01 */   ori      $v0, $v0, 0xa01
.L802400A0:
/* B9DA00 802400A0 24020003 */  addiu     $v0, $zero, 3
/* B9DA04 802400A4 10620019 */  beq       $v1, $v0, .L8024010C
/* B9DA08 802400A8 24020004 */   addiu    $v0, $zero, 4
/* B9DA0C 802400AC 10620021 */  beq       $v1, $v0, .L80240134
/* B9DA10 802400B0 3C02E300 */   lui      $v0, 0xe300
/* B9DA14 802400B4 08090057 */  j         .L8024015C
/* B9DA18 802400B8 34420A01 */   ori      $v0, $v0, 0xa01
.L802400BC:
/* B9DA1C 802400BC 3C018024 */  lui       $at, %hi(D_80241538)
/* B9DA20 802400C0 AC201538 */  sw        $zero, %lo(D_80241538)($at)
/* B9DA24 802400C4 08090055 */  j         .L80240154
/* B9DA28 802400C8 ACA40000 */   sw       $a0, ($a1)
.L802400CC:
/* B9DA2C 802400CC 3C038024 */  lui       $v1, %hi(D_80241538)
/* B9DA30 802400D0 24631538 */  addiu     $v1, $v1, %lo(D_80241538)
/* B9DA34 802400D4 8C620000 */  lw        $v0, ($v1)
/* B9DA38 802400D8 2442000A */  addiu     $v0, $v0, 0xa
/* B9DA3C 802400DC AC620000 */  sw        $v0, ($v1)
/* B9DA40 802400E0 28420100 */  slti      $v0, $v0, 0x100
/* B9DA44 802400E4 1440001C */  bnez      $v0, .L80240158
/* B9DA48 802400E8 3C02E300 */   lui      $v0, 0xe300
/* B9DA4C 802400EC 240200FF */  addiu     $v0, $zero, 0xff
/* B9DA50 802400F0 AC620000 */  sw        $v0, ($v1)
/* B9DA54 802400F4 24020014 */  addiu     $v0, $zero, 0x14
/* B9DA58 802400F8 3C018024 */  lui       $at, %hi(D_80241534)
/* B9DA5C 802400FC AC221534 */  sw        $v0, %lo(D_80241534)($at)
/* B9DA60 80240100 24020003 */  addiu     $v0, $zero, 3
/* B9DA64 80240104 08090055 */  j         .L80240154
/* B9DA68 80240108 ACA20000 */   sw       $v0, ($a1)
.L8024010C:
/* B9DA6C 8024010C 3C038024 */  lui       $v1, %hi(D_80241534)
/* B9DA70 80240110 24631534 */  addiu     $v1, $v1, %lo(D_80241534)
/* B9DA74 80240114 8C620000 */  lw        $v0, ($v1)
/* B9DA78 80240118 2442FFFF */  addiu     $v0, $v0, -1
/* B9DA7C 8024011C 0441000D */  bgez      $v0, .L80240154
/* B9DA80 80240120 AC620000 */   sw       $v0, ($v1)
/* B9DA84 80240124 24020004 */  addiu     $v0, $zero, 4
/* B9DA88 80240128 AC600000 */  sw        $zero, ($v1)
/* B9DA8C 8024012C 08090055 */  j         .L80240154
/* B9DA90 80240130 ACA20000 */   sw       $v0, ($a1)
.L80240134:
/* B9DA94 80240134 3C038024 */  lui       $v1, %hi(D_80241538)
/* B9DA98 80240138 24631538 */  addiu     $v1, $v1, %lo(D_80241538)
/* B9DA9C 8024013C 8C620000 */  lw        $v0, ($v1)
/* B9DAA0 80240140 2442FFF6 */  addiu     $v0, $v0, -0xa
/* B9DAA4 80240144 04410003 */  bgez      $v0, .L80240154
/* B9DAA8 80240148 AC620000 */   sw       $v0, ($v1)
/* B9DAAC 8024014C AC600000 */  sw        $zero, ($v1)
/* B9DAB0 80240150 ACA00000 */  sw        $zero, ($a1)
.L80240154:
/* B9DAB4 80240154 3C02E300 */  lui       $v0, 0xe300
.L80240158:
/* B9DAB8 80240158 34420A01 */  ori       $v0, $v0, 0xa01
.L8024015C:
/* B9DABC 8024015C 3C06FC12 */  lui       $a2, 0xfc12
/* B9DAC0 80240160 34C6160A */  ori       $a2, $a2, 0x160a
/* B9DAC4 80240164 3C08E200 */  lui       $t0, 0xe200
/* B9DAC8 80240168 3508001C */  ori       $t0, $t0, 0x1c
/* B9DACC 8024016C 3C07C810 */  lui       $a3, 0xc810
/* B9DAD0 80240170 3C05800A */  lui       $a1, %hi(D_8009A66C)
/* B9DAD4 80240174 24A5A66C */  addiu     $a1, $a1, %lo(D_8009A66C)
/* B9DAD8 80240178 8CA30000 */  lw        $v1, ($a1)
/* B9DADC 8024017C 34E74DD8 */  ori       $a3, $a3, 0x4dd8
/* B9DAE0 80240180 0060202D */  daddu     $a0, $v1, $zero
/* B9DAE4 80240184 24630008 */  addiu     $v1, $v1, 8
/* B9DAE8 80240188 ACA30000 */  sw        $v1, ($a1)
/* B9DAEC 8024018C AC820000 */  sw        $v0, ($a0)
/* B9DAF0 80240190 3C020010 */  lui       $v0, 0x10
/* B9DAF4 80240194 AC820004 */  sw        $v0, 4($a0)
/* B9DAF8 80240198 24620008 */  addiu     $v0, $v1, 8
/* B9DAFC 8024019C ACA20000 */  sw        $v0, ($a1)
/* B9DB00 802401A0 3C048024 */  lui       $a0, %hi(D_8024153B)
/* B9DB04 802401A4 9084153B */  lbu       $a0, %lo(D_8024153B)($a0)
/* B9DB08 802401A8 3C02FA00 */  lui       $v0, 0xfa00
/* B9DB0C 802401AC AC620000 */  sw        $v0, ($v1)
/* B9DB10 802401B0 24620010 */  addiu     $v0, $v1, 0x10
/* B9DB14 802401B4 AC640004 */  sw        $a0, 4($v1)
/* B9DB18 802401B8 ACA20000 */  sw        $v0, ($a1)
/* B9DB1C 802401BC 2402FFF8 */  addiu     $v0, $zero, -8
/* B9DB20 802401C0 AC62000C */  sw        $v0, 0xc($v1)
/* B9DB24 802401C4 24620018 */  addiu     $v0, $v1, 0x18
/* B9DB28 802401C8 AC660008 */  sw        $a2, 8($v1)
/* B9DB2C 802401CC ACA20000 */  sw        $v0, ($a1)
/* B9DB30 802401D0 AC680010 */  sw        $t0, 0x10($v1)
/* B9DB34 802401D4 03E00008 */  jr        $ra
/* B9DB38 802401D8 AC670014 */   sw       $a3, 0x14($v1)
