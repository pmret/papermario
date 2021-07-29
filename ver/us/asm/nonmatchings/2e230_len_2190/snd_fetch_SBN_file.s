.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel snd_fetch_SBN_file
/* 2F87C 8005447C 27BDFFF8 */  addiu     $sp, $sp, -8
/* 2F880 80054480 3C07800A */  lui       $a3, %hi(D_8009A5C0)
/* 2F884 80054484 8CE7A5C0 */  lw        $a3, %lo(D_8009A5C0)($a3)
/* 2F888 80054488 00A0482D */  daddu     $t1, $a1, $zero
/* 2F88C 8005448C 8CE20024 */  lw        $v0, 0x24($a3)
/* 2F890 80054490 0082102B */  sltu      $v0, $a0, $v0
/* 2F894 80054494 10400014 */  beqz      $v0, .L800544E8
/* 2F898 80054498 0000402D */   daddu    $t0, $zero, $zero
/* 2F89C 8005449C 3C0500FF */  lui       $a1, 0xff
/* 2F8A0 800544A0 34A5FFFF */  ori       $a1, $a1, 0xffff
/* 2F8A4 800544A4 8CE30020 */  lw        $v1, 0x20($a3)
/* 2F8A8 800544A8 000410C0 */  sll       $v0, $a0, 3
/* 2F8AC 800544AC 00621821 */  addu      $v1, $v1, $v0
/* 2F8B0 800544B0 8C620000 */  lw        $v0, ($v1)
/* 2F8B4 800544B4 8CE4001C */  lw        $a0, 0x1c($a3)
/* 2F8B8 800544B8 00451024 */  and       $v0, $v0, $a1
/* 2F8BC 800544BC 00442021 */  addu      $a0, $v0, $a0
/* 2F8C0 800544C0 AFA40000 */  sw        $a0, ($sp)
/* 2F8C4 800544C4 8C620004 */  lw        $v0, 4($v1)
/* 2F8C8 800544C8 AFA20004 */  sw        $v0, 4($sp)
/* 2F8CC 800544CC 00021602 */  srl       $v0, $v0, 0x18
/* 2F8D0 800544D0 54490006 */  bnel      $v0, $t1, .L800544EC
/* 2F8D4 800544D4 24080066 */   addiu    $t0, $zero, 0x66
/* 2F8D8 800544D8 ACC40000 */  sw        $a0, ($a2)
/* 2F8DC 800544DC 8FA20004 */  lw        $v0, 4($sp)
/* 2F8E0 800544E0 0801513B */  j         .L800544EC
/* 2F8E4 800544E4 ACC20004 */   sw       $v0, 4($a2)
.L800544E8:
/* 2F8E8 800544E8 24080065 */  addiu     $t0, $zero, 0x65
.L800544EC:
/* 2F8EC 800544EC 0100102D */  daddu     $v0, $t0, $zero
/* 2F8F0 800544F0 03E00008 */  jr        $ra
/* 2F8F4 800544F4 27BD0008 */   addiu    $sp, $sp, 8
