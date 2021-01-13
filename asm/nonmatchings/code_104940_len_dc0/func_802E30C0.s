.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E30C0
/* 104940 802E30C0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 104944 802E30C4 AFB00010 */  sw        $s0, 0x10($sp)
/* 104948 802E30C8 3C10800A */  lui       $s0, %hi(gMasterGfxPos)
/* 10494C 802E30CC 8E10A66C */  lw        $s0, %lo(gMasterGfxPos)($s0)
/* 104950 802E30D0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 104954 802E30D4 0C04417A */  jal       get_entity_by_index
/* 104958 802E30D8 00000000 */   nop
/* 10495C 802E30DC 3C04E300 */  lui       $a0, 0xe300
/* 104960 802E30E0 34841001 */  ori       $a0, $a0, 0x1001
/* 104964 802E30E4 3C05D700 */  lui       $a1, 0xd700
/* 104968 802E30E8 34A50002 */  ori       $a1, $a1, 2
/* 10496C 802E30EC 0200182D */  daddu     $v1, $s0, $zero
/* 104970 802E30F0 26100008 */  addiu     $s0, $s0, 8
/* 104974 802E30F4 AC640000 */  sw        $a0, ($v1)
/* 104978 802E30F8 0200202D */  daddu     $a0, $s0, $zero
/* 10497C 802E30FC AC600004 */  sw        $zero, 4($v1)
/* 104980 802E3100 2403FFFF */  addiu     $v1, $zero, -1
/* 104984 802E3104 AC850000 */  sw        $a1, ($a0)
/* 104988 802E3108 0040282D */  daddu     $a1, $v0, $zero
/* 10498C 802E310C AC830004 */  sw        $v1, 4($a0)
/* 104990 802E3110 90A2000B */  lbu       $v0, 0xb($a1)
/* 104994 802E3114 2C4200FF */  sltiu     $v0, $v0, 0xff
/* 104998 802E3118 14400011 */  bnez      $v0, .L802E3160
/* 10499C 802E311C 26100008 */   addiu    $s0, $s0, 8
/* 1049A0 802E3120 0200282D */  daddu     $a1, $s0, $zero
/* 1049A4 802E3124 26100008 */  addiu     $s0, $s0, 8
/* 1049A8 802E3128 3C07E200 */  lui       $a3, 0xe200
/* 1049AC 802E312C 34E7001C */  ori       $a3, $a3, 0x1c
/* 1049B0 802E3130 3C060055 */  lui       $a2, 0x55
/* 1049B4 802E3134 34C62078 */  ori       $a2, $a2, 0x2078
/* 1049B8 802E3138 0200182D */  daddu     $v1, $s0, $zero
/* 1049BC 802E313C 26100008 */  addiu     $s0, $s0, 8
/* 1049C0 802E3140 3C04FC12 */  lui       $a0, 0xfc12
/* 1049C4 802E3144 34841824 */  ori       $a0, $a0, 0x1824
/* 1049C8 802E3148 3C02FF33 */  lui       $v0, 0xff33
/* 1049CC 802E314C 3442FFFF */  ori       $v0, $v0, 0xffff
/* 1049D0 802E3150 ACA70000 */  sw        $a3, ($a1)
/* 1049D4 802E3154 ACA60004 */  sw        $a2, 4($a1)
/* 1049D8 802E3158 080B8C65 */  j         .L802E3194
/* 1049DC 802E315C AC640000 */   sw       $a0, ($v1)
.L802E3160:
/* 1049E0 802E3160 0200202D */  daddu     $a0, $s0, $zero
/* 1049E4 802E3164 26100008 */  addiu     $s0, $s0, 8
/* 1049E8 802E3168 3C03FCFF */  lui       $v1, 0xfcff
/* 1049EC 802E316C 3463B3FF */  ori       $v1, $v1, 0xb3ff
/* 1049F0 802E3170 3C02FF2C */  lui       $v0, 0xff2c
/* 1049F4 802E3174 3442FE7F */  ori       $v0, $v0, 0xfe7f
/* 1049F8 802E3178 AC830000 */  sw        $v1, ($a0)
/* 1049FC 802E317C 0200182D */  daddu     $v1, $s0, $zero
/* 104A00 802E3180 AC820004 */  sw        $v0, 4($a0)
/* 104A04 802E3184 3C02FA00 */  lui       $v0, 0xfa00
/* 104A08 802E3188 AC620000 */  sw        $v0, ($v1)
/* 104A0C 802E318C 90A2000B */  lbu       $v0, 0xb($a1)
/* 104A10 802E3190 26100008 */  addiu     $s0, $s0, 8
.L802E3194:
/* 104A14 802E3194 AC620004 */  sw        $v0, 4($v1)
/* 104A18 802E3198 8FBF0014 */  lw        $ra, 0x14($sp)
/* 104A1C 802E319C 3C01800A */  lui       $at, %hi(gMasterGfxPos)
/* 104A20 802E31A0 AC30A66C */  sw        $s0, %lo(gMasterGfxPos)($at)
/* 104A24 802E31A4 8FB00010 */  lw        $s0, 0x10($sp)
/* 104A28 802E31A8 03E00008 */  jr        $ra
/* 104A2C 802E31AC 27BD0018 */   addiu    $sp, $sp, 0x18
