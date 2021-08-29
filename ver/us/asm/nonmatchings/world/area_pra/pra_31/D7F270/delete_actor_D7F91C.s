.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel btl_delete_actor_D7F91C
/* D7F91C 80240BBC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D7F920 80240BC0 AFB10014 */  sw        $s1, 0x14($sp)
/* D7F924 80240BC4 0080882D */  daddu     $s1, $a0, $zero
/* D7F928 80240BC8 AFBF0018 */  sw        $ra, 0x18($sp)
/* D7F92C 80240BCC AFB00010 */  sw        $s0, 0x10($sp)
/* D7F930 80240BD0 8E22000C */  lw        $v0, 0xc($s1)
/* D7F934 80240BD4 0C0B1EAF */  jal       evt_get_variable
/* D7F938 80240BD8 8C450000 */   lw       $a1, ($v0)
/* D7F93C 80240BDC 0220202D */  daddu     $a0, $s1, $zero
/* D7F940 80240BE0 3C05FD05 */  lui       $a1, 0xfd05
/* D7F944 80240BE4 34A50F80 */  ori       $a1, $a1, 0xf80
/* D7F948 80240BE8 0C0B1EAF */  jal       evt_get_variable
/* D7F94C 80240BEC 0040802D */   daddu    $s0, $v0, $zero
/* D7F950 80240BF0 00101840 */  sll       $v1, $s0, 1
/* D7F954 80240BF4 00701821 */  addu      $v1, $v1, $s0
/* D7F958 80240BF8 000318C0 */  sll       $v1, $v1, 3
/* D7F95C 80240BFC 00431021 */  addu      $v0, $v0, $v1
/* D7F960 80240C00 C4400014 */  lwc1      $f0, 0x14($v0)
/* D7F964 80240C04 2402005A */  addiu     $v0, $zero, 0x5a
/* D7F968 80240C08 4600008D */  trunc.w.s $f2, $f0
/* D7F96C 80240C0C 44031000 */  mfc1      $v1, $f2
/* D7F970 80240C10 00000000 */  nop
/* D7F974 80240C14 1062000F */  beq       $v1, $v0, .L80240C54
/* D7F978 80240C18 2862005B */   slti     $v0, $v1, 0x5b
/* D7F97C 80240C1C 10400005 */  beqz      $v0, .L80240C34
/* D7F980 80240C20 240200B4 */   addiu    $v0, $zero, 0xb4
/* D7F984 80240C24 5060000C */  beql      $v1, $zero, .L80240C58
/* D7F988 80240C28 AE220084 */   sw       $v0, 0x84($s1)
/* D7F98C 80240C2C 08090316 */  j         .L80240C58
/* D7F990 80240C30 00000000 */   nop
.L80240C34:
/* D7F994 80240C34 10620005 */  beq       $v1, $v0, .L80240C4C
/* D7F998 80240C38 2402010E */   addiu    $v0, $zero, 0x10e
/* D7F99C 80240C3C 50620006 */  beql      $v1, $v0, .L80240C58
/* D7F9A0 80240C40 AE230084 */   sw       $v1, 0x84($s1)
/* D7F9A4 80240C44 08090316 */  j         .L80240C58
/* D7F9A8 80240C48 00000000 */   nop
.L80240C4C:
/* D7F9AC 80240C4C 08090316 */  j         .L80240C58
/* D7F9B0 80240C50 AE200084 */   sw       $zero, 0x84($s1)
.L80240C54:
/* D7F9B4 80240C54 AE230084 */  sw        $v1, 0x84($s1)
.L80240C58:
/* D7F9B8 80240C58 8FBF0018 */  lw        $ra, 0x18($sp)
/* D7F9BC 80240C5C 8FB10014 */  lw        $s1, 0x14($sp)
/* D7F9C0 80240C60 8FB00010 */  lw        $s0, 0x10($sp)
/* D7F9C4 80240C64 24020002 */  addiu     $v0, $zero, 2
/* D7F9C8 80240C68 03E00008 */  jr        $ra
/* D7F9CC 80240C6C 27BD0020 */   addiu    $sp, $sp, 0x20
