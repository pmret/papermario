.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006C840
/* 47C40 8006C840 00001821 */  addu      $v1, $zero, $zero
/* 47C44 8006C844 24050400 */  addiu     $a1, $zero, 0x400
/* 47C48 8006C848 3084FFFF */  andi      $a0, $a0, 0xffff
/* 47C4C 8006C84C 00851024 */  and       $v0, $a0, $a1
.L8006C850:
/* 47C50 8006C850 10400006 */  beqz      $v0, .L8006C86C
/* 47C54 8006C854 00031840 */   sll      $v1, $v1, 1
/* 47C58 8006C858 30620020 */  andi      $v0, $v1, 0x20
/* 47C5C 8006C85C 50400006 */  beql      $v0, $zero, .L8006C878
/* 47C60 8006C860 24630001 */   addiu    $v1, $v1, 1
/* 47C64 8006C864 0801B21E */  j         .L8006C878
/* 47C68 8006C868 38630014 */   xori     $v1, $v1, 0x14
.L8006C86C:
/* 47C6C 8006C86C 30620020 */  andi      $v0, $v1, 0x20
/* 47C70 8006C870 54400001 */  bnel      $v0, $zero, .L8006C878
/* 47C74 8006C874 38630015 */   xori     $v1, $v1, 0x15
.L8006C878:
/* 47C78 8006C878 00052842 */  srl       $a1, $a1, 1
/* 47C7C 8006C87C 14A0FFF4 */  bnez      $a1, .L8006C850
/* 47C80 8006C880 00851024 */   and      $v0, $a0, $a1
/* 47C84 8006C884 24050005 */  addiu     $a1, $zero, 5
/* 47C88 8006C888 00031840 */  sll       $v1, $v1, 1
.L8006C88C:
/* 47C8C 8006C88C 30620020 */  andi      $v0, $v1, 0x20
/* 47C90 8006C890 54400001 */  bnel      $v0, $zero, .L8006C898
/* 47C94 8006C894 38630015 */   xori     $v1, $v1, 0x15
.L8006C898:
/* 47C98 8006C898 24A5FFFF */  addiu     $a1, $a1, -1
/* 47C9C 8006C89C 54A0FFFB */  bnel      $a1, $zero, .L8006C88C
/* 47CA0 8006C8A0 00031840 */   sll      $v1, $v1, 1
/* 47CA4 8006C8A4 03E00008 */  jr        $ra
/* 47CA8 8006C8A8 3062001F */   andi     $v0, $v1, 0x1f
