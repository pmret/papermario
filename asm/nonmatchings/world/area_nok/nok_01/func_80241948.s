.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241948
/* 9C6D28 80241948 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9C6D2C 8024194C AFB10014 */  sw        $s1, 0x14($sp)
/* 9C6D30 80241950 0080882D */  daddu     $s1, $a0, $zero
/* 9C6D34 80241954 AFBF0018 */  sw        $ra, 0x18($sp)
/* 9C6D38 80241958 AFB00010 */  sw        $s0, 0x10($sp)
/* 9C6D3C 8024195C 8E30000C */  lw        $s0, 0xc($s1)
/* 9C6D40 80241960 8E050000 */  lw        $a1, ($s0)
/* 9C6D44 80241964 0C0B1EAF */  jal       get_variable
/* 9C6D48 80241968 26100004 */   addiu    $s0, $s0, 4
/* 9C6D4C 8024196C 00021880 */  sll       $v1, $v0, 2
/* 9C6D50 80241970 00621821 */  addu      $v1, $v1, $v0
/* 9C6D54 80241974 00031880 */  sll       $v1, $v1, 2
/* 9C6D58 80241978 00621823 */  subu      $v1, $v1, $v0
/* 9C6D5C 8024197C 000310C0 */  sll       $v0, $v1, 3
/* 9C6D60 80241980 00621821 */  addu      $v1, $v1, $v0
/* 9C6D64 80241984 000318C0 */  sll       $v1, $v1, 3
/* 9C6D68 80241988 3C01800B */  lui       $at, 0x800b
/* 9C6D6C 8024198C 00230821 */  addu      $at, $at, $v1
/* 9C6D70 80241990 C4221D98 */  lwc1      $f2, 0x1d98($at)
/* 9C6D74 80241994 3C014480 */  lui       $at, 0x4480
/* 9C6D78 80241998 44810000 */  mtc1      $at, $f0
/* 9C6D7C 8024199C 00000000 */  nop       
/* 9C6D80 802419A0 46001082 */  mul.s     $f2, $f2, $f0
/* 9C6D84 802419A4 00000000 */  nop       
/* 9C6D88 802419A8 3C01CD5B */  lui       $at, 0xcd5b
/* 9C6D8C 802419AC 34215858 */  ori       $at, $at, 0x5858
/* 9C6D90 802419B0 44810000 */  mtc1      $at, $f0
/* 9C6D94 802419B4 00000000 */  nop       
/* 9C6D98 802419B8 46001080 */  add.s     $f2, $f2, $f0
/* 9C6D9C 802419BC 8E050000 */  lw        $a1, ($s0)
/* 9C6DA0 802419C0 4600110D */  trunc.w.s $f4, $f2
/* 9C6DA4 802419C4 44062000 */  mfc1      $a2, $f4
/* 9C6DA8 802419C8 0C0B2026 */  jal       set_variable
/* 9C6DAC 802419CC 0220202D */   daddu    $a0, $s1, $zero
/* 9C6DB0 802419D0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9C6DB4 802419D4 8FB10014 */  lw        $s1, 0x14($sp)
/* 9C6DB8 802419D8 8FB00010 */  lw        $s0, 0x10($sp)
/* 9C6DBC 802419DC 24020002 */  addiu     $v0, $zero, 2
/* 9C6DC0 802419E0 03E00008 */  jr        $ra
/* 9C6DC4 802419E4 27BD0020 */   addiu    $sp, $sp, 0x20
