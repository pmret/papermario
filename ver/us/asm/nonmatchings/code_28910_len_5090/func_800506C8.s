.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800506C8
/* 2BAC8 800506C8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 2BACC 800506CC AFB00010 */  sw        $s0, 0x10($sp)
/* 2BAD0 800506D0 00A0802D */  daddu     $s0, $a1, $zero
/* 2BAD4 800506D4 AFB10014 */  sw        $s1, 0x14($sp)
/* 2BAD8 800506D8 0000882D */  daddu     $s1, $zero, $zero
/* 2BADC 800506DC AFB20018 */  sw        $s2, 0x18($sp)
/* 2BAE0 800506E0 0200902D */  daddu     $s2, $s0, $zero
/* 2BAE4 800506E4 1080001C */  beqz      $a0, .L80050758
/* 2BAE8 800506E8 AFBF001C */   sw       $ra, 0x1c($sp)
/* 2BAEC 800506EC 0C0135E5 */  jal       snd_get_player_with_song_name
/* 2BAF0 800506F0 00000000 */   nop
/* 2BAF4 800506F4 0040282D */  daddu     $a1, $v0, $zero
/* 2BAF8 800506F8 10A00017 */  beqz      $a1, .L80050758
/* 2BAFC 800506FC 00000000 */   nop
/* 2BB00 80050700 8CA2016C */  lw        $v0, 0x16c($a1)
/* 2BB04 80050704 10500014 */  beq       $v0, $s0, .L80050758
/* 2BB08 80050708 324200FF */   andi     $v0, $s2, 0xff
/* 2BB0C 8005070C 90A30170 */  lbu       $v1, 0x170($a1)
/* 2BB10 80050710 10620003 */  beq       $v1, $v0, .L80050720
/* 2BB14 80050714 ACB0016C */   sw       $s0, 0x16c($a1)
/* 2BB18 80050718 A0B00170 */  sb        $s0, 0x170($a1)
/* 2BB1C 8005071C 24110001 */  addiu     $s1, $zero, 1
.L80050720:
/* 2BB20 80050720 00101602 */  srl       $v0, $s0, 0x18
/* 2BB24 80050724 3042007F */  andi      $v0, $v0, 0x7f
/* 2BB28 80050728 A0A20171 */  sb        $v0, 0x171($a1)
/* 2BB2C 8005072C 0000202D */  daddu     $a0, $zero, $zero
/* 2BB30 80050730 24060001 */  addiu     $a2, $zero, 1
/* 2BB34 80050734 2403025C */  addiu     $v1, $zero, 0x25c
.L80050738:
/* 2BB38 80050738 12200002 */  beqz      $s1, .L80050744
/* 2BB3C 8005073C 00A31021 */   addu     $v0, $a1, $v1
/* 2BB40 80050740 A046004D */  sb        $a2, 0x4d($v0)
.L80050744:
/* 2BB44 80050744 A046004E */  sb        $a2, 0x4e($v0)
/* 2BB48 80050748 24840001 */  addiu     $a0, $a0, 1
/* 2BB4C 8005074C 28820010 */  slti      $v0, $a0, 0x10
/* 2BB50 80050750 1440FFF9 */  bnez      $v0, .L80050738
/* 2BB54 80050754 24630060 */   addiu    $v1, $v1, 0x60
.L80050758:
/* 2BB58 80050758 8FBF001C */  lw        $ra, 0x1c($sp)
/* 2BB5C 8005075C 8FB20018 */  lw        $s2, 0x18($sp)
/* 2BB60 80050760 8FB10014 */  lw        $s1, 0x14($sp)
/* 2BB64 80050764 8FB00010 */  lw        $s0, 0x10($sp)
/* 2BB68 80050768 03E00008 */  jr        $ra
/* 2BB6C 8005076C 27BD0020 */   addiu    $sp, $sp, 0x20
