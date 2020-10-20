.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406E0_A39BC0
/* A39BC0 802406E0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A39BC4 802406E4 AFBF0010 */  sw        $ra, 0x10($sp)
/* A39BC8 802406E8 8C82000C */  lw        $v0, 0xc($a0)
/* A39BCC 802406EC 0C0B1EAF */  jal       get_variable
/* A39BD0 802406F0 8C450000 */   lw       $a1, ($v0)
/* A39BD4 802406F4 0040182D */  daddu     $v1, $v0, $zero
/* A39BD8 802406F8 10600012 */  beqz      $v1, .L80240744
/* A39BDC 802406FC 0000202D */   daddu    $a0, $zero, $zero
/* A39BE0 80240700 8C620000 */  lw        $v0, ($v1)
/* A39BE4 80240704 5040000A */  beql      $v0, $zero, .L80240730
/* A39BE8 80240708 00041080 */   sll      $v0, $a0, 2
/* A39BEC 8024070C 3C058024 */  lui       $a1, 0x8024
/* A39BF0 80240710 24A56260 */  addiu     $a1, $a1, 0x6260
.L80240714:
/* A39BF4 80240714 24630004 */  addiu     $v1, $v1, 4
/* A39BF8 80240718 24840001 */  addiu     $a0, $a0, 1
/* A39BFC 8024071C ACA20000 */  sw        $v0, ($a1)
/* A39C00 80240720 8C620000 */  lw        $v0, ($v1)
/* A39C04 80240724 1440FFFB */  bnez      $v0, .L80240714
/* A39C08 80240728 24A50004 */   addiu    $a1, $a1, 4
/* A39C0C 8024072C 00041080 */  sll       $v0, $a0, 2
.L80240730:
/* A39C10 80240730 3C018024 */  lui       $at, 0x8024
/* A39C14 80240734 00220821 */  addu      $at, $at, $v0
/* A39C18 80240738 AC206260 */  sw        $zero, 0x6260($at)
/* A39C1C 8024073C 080901DB */  j         .L8024076C
/* A39C20 80240740 00000000 */   nop      
.L80240744:
/* A39C24 80240744 3C038024 */  lui       $v1, 0x8024
/* A39C28 80240748 24636260 */  addiu     $v1, $v1, 0x6260
/* A39C2C 8024074C 0060282D */  daddu     $a1, $v1, $zero
.L80240750:
/* A39C30 80240750 24820010 */  addiu     $v0, $a0, 0x10
/* A39C34 80240754 AC620000 */  sw        $v0, ($v1)
/* A39C38 80240758 24630004 */  addiu     $v1, $v1, 4
/* A39C3C 8024075C 24840001 */  addiu     $a0, $a0, 1
/* A39C40 80240760 28820070 */  slti      $v0, $a0, 0x70
/* A39C44 80240764 1440FFFA */  bnez      $v0, .L80240750
/* A39C48 80240768 ACA001C0 */   sw       $zero, 0x1c0($a1)
.L8024076C:
/* A39C4C 8024076C 8FBF0010 */  lw        $ra, 0x10($sp)
/* A39C50 80240770 24020002 */  addiu     $v0, $zero, 2
/* A39C54 80240774 03E00008 */  jr        $ra
/* A39C58 80240778 27BD0018 */   addiu    $sp, $sp, 0x18
