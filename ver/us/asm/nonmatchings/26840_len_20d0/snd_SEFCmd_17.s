.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel snd_SEFCmd_17
/* 287A0 8004D3A0 8CA60000 */  lw        $a2, ($a1)
/* 287A4 8004D3A4 0000182D */  daddu     $v1, $zero, $zero
.L8004D3A8:
/* 287A8 8004D3A8 948200A0 */  lhu       $v0, 0xa0($a0)
/* 287AC 8004D3AC 1440000C */  bnez      $v0, .L8004D3E0
/* 287B0 8004D3B0 24630001 */   addiu    $v1, $v1, 1
/* 287B4 8004D3B4 90C20000 */  lbu       $v0, ($a2)
/* 287B8 8004D3B8 90C30001 */  lbu       $v1, 1($a2)
/* 287BC 8004D3BC 00021200 */  sll       $v0, $v0, 8
/* 287C0 8004D3C0 00621821 */  addu      $v1, $v1, $v0
/* 287C4 8004D3C4 A48300A0 */  sh        $v1, 0xa0($a0)
/* 287C8 8004D3C8 90C20002 */  lbu       $v0, 2($a2)
/* 287CC 8004D3CC 90C30003 */  lbu       $v1, 3($a2)
/* 287D0 8004D3D0 00021200 */  sll       $v0, $v0, 8
/* 287D4 8004D3D4 00621821 */  addu      $v1, $v1, $v0
/* 287D8 8004D3D8 080134FB */  j         .L8004D3EC
/* 287DC 8004D3DC A48300A2 */   sh       $v1, 0xa2($a0)
.L8004D3E0:
/* 287E0 8004D3E0 2C620004 */  sltiu     $v0, $v1, 4
/* 287E4 8004D3E4 1440FFF0 */  bnez      $v0, .L8004D3A8
/* 287E8 8004D3E8 24840006 */   addiu    $a0, $a0, 6
.L8004D3EC:
/* 287EC 8004D3EC 24C20004 */  addiu     $v0, $a2, 4
/* 287F0 8004D3F0 03E00008 */  jr        $ra
/* 287F4 8004D3F4 ACA20000 */   sw       $v0, ($a1)
