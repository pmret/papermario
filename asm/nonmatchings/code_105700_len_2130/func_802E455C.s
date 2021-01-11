.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E455C
/* 105DDC 802E455C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 105DE0 802E4560 AFB00010 */  sw        $s0, 0x10($sp)
/* 105DE4 802E4564 3C10800A */  lui       $s0, %hi(gMasterGfxPos)
/* 105DE8 802E4568 8E10A66C */  lw        $s0, %lo(gMasterGfxPos)($s0)
/* 105DEC 802E456C AFBF0014 */  sw        $ra, 0x14($sp)
/* 105DF0 802E4570 0C04417A */  jal       get_entity_by_index
/* 105DF4 802E4574 00000000 */   nop      
/* 105DF8 802E4578 3C04E300 */  lui       $a0, 0xe300
/* 105DFC 802E457C 34841001 */  ori       $a0, $a0, 0x1001
/* 105E00 802E4580 3C05D700 */  lui       $a1, 0xd700
/* 105E04 802E4584 34A50002 */  ori       $a1, $a1, 2
/* 105E08 802E4588 0200182D */  daddu     $v1, $s0, $zero
/* 105E0C 802E458C 26100008 */  addiu     $s0, $s0, 8
/* 105E10 802E4590 AC640000 */  sw        $a0, ($v1)
/* 105E14 802E4594 0200202D */  daddu     $a0, $s0, $zero
/* 105E18 802E4598 AC600004 */  sw        $zero, 4($v1)
/* 105E1C 802E459C 2403FFFF */  addiu     $v1, $zero, -1
/* 105E20 802E45A0 AC850000 */  sw        $a1, ($a0)
/* 105E24 802E45A4 0040282D */  daddu     $a1, $v0, $zero
/* 105E28 802E45A8 AC830004 */  sw        $v1, 4($a0)
/* 105E2C 802E45AC 90A2000B */  lbu       $v0, 0xb($a1)
/* 105E30 802E45B0 2C4200FF */  sltiu     $v0, $v0, 0xff
/* 105E34 802E45B4 14400011 */  bnez      $v0, .L802E45FC
/* 105E38 802E45B8 26100008 */   addiu    $s0, $s0, 8
/* 105E3C 802E45BC 0200282D */  daddu     $a1, $s0, $zero
/* 105E40 802E45C0 26100008 */  addiu     $s0, $s0, 8
/* 105E44 802E45C4 3C07E200 */  lui       $a3, 0xe200
/* 105E48 802E45C8 34E7001C */  ori       $a3, $a3, 0x1c
/* 105E4C 802E45CC 3C060055 */  lui       $a2, 0x55
/* 105E50 802E45D0 34C62078 */  ori       $a2, $a2, 0x2078
/* 105E54 802E45D4 0200182D */  daddu     $v1, $s0, $zero
/* 105E58 802E45D8 26100008 */  addiu     $s0, $s0, 8
/* 105E5C 802E45DC 3C04FC12 */  lui       $a0, 0xfc12
/* 105E60 802E45E0 34841824 */  ori       $a0, $a0, 0x1824
/* 105E64 802E45E4 3C02FF33 */  lui       $v0, 0xff33
/* 105E68 802E45E8 3442FFFF */  ori       $v0, $v0, 0xffff
/* 105E6C 802E45EC ACA70000 */  sw        $a3, ($a1)
/* 105E70 802E45F0 ACA60004 */  sw        $a2, 4($a1)
/* 105E74 802E45F4 080B918C */  j         .L802E4630
/* 105E78 802E45F8 AC640000 */   sw       $a0, ($v1)
.L802E45FC:
/* 105E7C 802E45FC 0200202D */  daddu     $a0, $s0, $zero
/* 105E80 802E4600 26100008 */  addiu     $s0, $s0, 8
/* 105E84 802E4604 3C03FCFF */  lui       $v1, 0xfcff
/* 105E88 802E4608 3463B3FF */  ori       $v1, $v1, 0xb3ff
/* 105E8C 802E460C 3C02FF2C */  lui       $v0, 0xff2c
/* 105E90 802E4610 3442FE7F */  ori       $v0, $v0, 0xfe7f
/* 105E94 802E4614 AC830000 */  sw        $v1, ($a0)
/* 105E98 802E4618 0200182D */  daddu     $v1, $s0, $zero
/* 105E9C 802E461C AC820004 */  sw        $v0, 4($a0)
/* 105EA0 802E4620 3C02FA00 */  lui       $v0, 0xfa00
/* 105EA4 802E4624 AC620000 */  sw        $v0, ($v1)
/* 105EA8 802E4628 90A2000B */  lbu       $v0, 0xb($a1)
/* 105EAC 802E462C 26100008 */  addiu     $s0, $s0, 8
.L802E4630:
/* 105EB0 802E4630 AC620004 */  sw        $v0, 4($v1)
/* 105EB4 802E4634 8FBF0014 */  lw        $ra, 0x14($sp)
/* 105EB8 802E4638 3C01800A */  lui       $at, %hi(gMasterGfxPos)
/* 105EBC 802E463C AC30A66C */  sw        $s0, %lo(gMasterGfxPos)($at)
/* 105EC0 802E4640 8FB00010 */  lw        $s0, 0x10($sp)
/* 105EC4 802E4644 03E00008 */  jr        $ra
/* 105EC8 802E4648 27BD0018 */   addiu    $sp, $sp, 0x18
