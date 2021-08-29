.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A91A0_42DBB0
/* 42DBB0 802A91A0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 42DBB4 802A91A4 AFB20018 */  sw        $s2, 0x18($sp)
/* 42DBB8 802A91A8 0080902D */  daddu     $s2, $a0, $zero
/* 42DBBC 802A91AC AFB10014 */  sw        $s1, 0x14($sp)
/* 42DBC0 802A91B0 3C11802A */  lui       $s1, %hi(gActionCommandStatus)
/* 42DBC4 802A91B4 2631FBE0 */  addiu     $s1, $s1, %lo(gActionCommandStatus)
/* 42DBC8 802A91B8 AFB3001C */  sw        $s3, 0x1c($sp)
/* 42DBCC 802A91BC 3C13800E */  lui       $s3, %hi(gBattleStatus)
/* 42DBD0 802A91C0 2673C070 */  addiu     $s3, $s3, %lo(gBattleStatus)
/* 42DBD4 802A91C4 AFBF0020 */  sw        $ra, 0x20($sp)
/* 42DBD8 802A91C8 AFB00010 */  sw        $s0, 0x10($sp)
/* 42DBDC 802A91CC 82620083 */  lb        $v0, 0x83($s3)
/* 42DBE0 802A91D0 8E50000C */  lw        $s0, 0xc($s2)
/* 42DBE4 802A91D4 10400029 */  beqz      $v0, .L802A927C
/* 42DBE8 802A91D8 0260182D */   daddu    $v1, $s3, $zero
/* 42DBEC 802A91DC 0C09A216 */  jal       func_80268858
/* 42DBF0 802A91E0 00000000 */   nop
/* 42DBF4 802A91E4 8E050000 */  lw        $a1, ($s0)
/* 42DBF8 802A91E8 26100004 */  addiu     $s0, $s0, 4
/* 42DBFC 802A91EC 0C0B1EAF */  jal       evt_get_variable
/* 42DC00 802A91F0 0240202D */   daddu    $a0, $s2, $zero
/* 42DC04 802A91F4 A622004E */  sh        $v0, 0x4e($s1)
/* 42DC08 802A91F8 8E050000 */  lw        $a1, ($s0)
/* 42DC0C 802A91FC 26100004 */  addiu     $s0, $s0, 4
/* 42DC10 802A9200 0C0B1EAF */  jal       evt_get_variable
/* 42DC14 802A9204 0240202D */   daddu    $a0, $s2, $zero
/* 42DC18 802A9208 A6220052 */  sh        $v0, 0x52($s1)
/* 42DC1C 802A920C 8E050000 */  lw        $a1, ($s0)
/* 42DC20 802A9210 26100004 */  addiu     $s0, $s0, 4
/* 42DC24 802A9214 0C0B1EAF */  jal       evt_get_variable
/* 42DC28 802A9218 0240202D */   daddu    $a0, $s2, $zero
/* 42DC2C 802A921C 00022400 */  sll       $a0, $v0, 0x10
/* 42DC30 802A9220 00042403 */  sra       $a0, $a0, 0x10
/* 42DC34 802A9224 0C09A089 */  jal       func_80268224
/* 42DC38 802A9228 A6220050 */   sh       $v0, 0x50($s1)
/* 42DC3C 802A922C A6220050 */  sh        $v0, 0x50($s1)
/* 42DC40 802A9230 8E050000 */  lw        $a1, ($s0)
/* 42DC44 802A9234 0C0B1EAF */  jal       evt_get_variable
/* 42DC48 802A9238 0240202D */   daddu    $a0, $s2, $zero
/* 42DC4C 802A923C 3C04FFFF */  lui       $a0, 0xffff
/* 42DC50 802A9240 34847FFF */  ori       $a0, $a0, 0x7fff
/* 42DC54 802A9244 A6220064 */  sh        $v0, 0x64($s1)
/* 42DC58 802A9248 A2200060 */  sb        $zero, 0x60($s1)
/* 42DC5C 802A924C A6200044 */  sh        $zero, 0x44($s1)
/* 42DC60 802A9250 A6200048 */  sh        $zero, 0x48($s1)
/* 42DC64 802A9254 8E620000 */  lw        $v0, ($s3)
/* 42DC68 802A9258 2403000A */  addiu     $v1, $zero, 0xa
/* 42DC6C 802A925C A2600081 */  sb        $zero, 0x81($s3)
/* 42DC70 802A9260 A2600086 */  sb        $zero, 0x86($s3)
/* 42DC74 802A9264 A623004C */  sh        $v1, 0x4c($s1)
/* 42DC78 802A9268 00441024 */  and       $v0, $v0, $a0
/* 42DC7C 802A926C 0C09A446 */  jal       func_80269118
/* 42DC80 802A9270 AE620000 */   sw       $v0, ($s3)
/* 42DC84 802A9274 080AA4A1 */  j         .L802A9284
/* 42DC88 802A9278 24020002 */   addiu    $v0, $zero, 2
.L802A927C:
/* 42DC8C 802A927C A0600081 */  sb        $zero, 0x81($v1)
/* 42DC90 802A9280 24020002 */  addiu     $v0, $zero, 2
.L802A9284:
/* 42DC94 802A9284 8FBF0020 */  lw        $ra, 0x20($sp)
/* 42DC98 802A9288 8FB3001C */  lw        $s3, 0x1c($sp)
/* 42DC9C 802A928C 8FB20018 */  lw        $s2, 0x18($sp)
/* 42DCA0 802A9290 8FB10014 */  lw        $s1, 0x14($sp)
/* 42DCA4 802A9294 8FB00010 */  lw        $s0, 0x10($sp)
/* 42DCA8 802A9298 03E00008 */  jr        $ra
/* 42DCAC 802A929C 27BD0028 */   addiu    $sp, $sp, 0x28
