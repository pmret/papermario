.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osContAddressCrc
/* 47C60 8006C860 00001821 */  addu      $v1, $zero, $zero
/* 47C64 8006C864 24050400 */  addiu     $a1, $zero, 0x400
/* 47C68 8006C868 3084FFFF */  andi      $a0, $a0, 0xffff
/* 47C6C 8006C86C 00851024 */  and       $v0, $a0, $a1
.L8006C870:
/* 47C70 8006C870 10400006 */  beqz      $v0, .L8006C88C
/* 47C74 8006C874 00031840 */   sll      $v1, $v1, 1
/* 47C78 8006C878 30620020 */  andi      $v0, $v1, 0x20
/* 47C7C 8006C87C 50400006 */  beql      $v0, $zero, .L8006C898
/* 47C80 8006C880 24630001 */   addiu    $v1, $v1, 1
/* 47C84 8006C884 0801B226 */  j         .L8006C898
/* 47C88 8006C888 38630014 */   xori     $v1, $v1, 0x14
.L8006C88C:
/* 47C8C 8006C88C 30620020 */  andi      $v0, $v1, 0x20
/* 47C90 8006C890 54400001 */  bnel      $v0, $zero, .L8006C898
/* 47C94 8006C894 38630015 */   xori     $v1, $v1, 0x15
.L8006C898:
/* 47C98 8006C898 00052842 */  srl       $a1, $a1, 1
/* 47C9C 8006C89C 14A0FFF4 */  bnez      $a1, .L8006C870
/* 47CA0 8006C8A0 00851024 */   and      $v0, $a0, $a1
/* 47CA4 8006C8A4 24050005 */  addiu     $a1, $zero, 5
/* 47CA8 8006C8A8 00031840 */  sll       $v1, $v1, 1
.L8006C8AC:
/* 47CAC 8006C8AC 30620020 */  andi      $v0, $v1, 0x20
/* 47CB0 8006C8B0 54400001 */  bnel      $v0, $zero, .L8006C8B8
/* 47CB4 8006C8B4 38630015 */   xori     $v1, $v1, 0x15
.L8006C8B8:
/* 47CB8 8006C8B8 24A5FFFF */  addiu     $a1, $a1, -1
/* 47CBC 8006C8BC 54A0FFFB */  bnel      $a1, $zero, .L8006C8AC
/* 47CC0 8006C8C0 00031840 */   sll      $v1, $v1, 1
/* 47CC4 8006C8C4 03E00008 */  jr        $ra
/* 47CC8 8006C8C8 3062001F */   andi     $v0, $v1, 0x1f
