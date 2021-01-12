.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80238B50_70C860
/* 70C860 80238B50 3C02800E */  lui       $v0, %hi(gBattleStatus+0xDC)
/* 70C864 80238B54 8C42C14C */  lw        $v0, %lo(gBattleStatus+0xDC)($v0)
/* 70C868 80238B58 8C420008 */  lw        $v0, 8($v0)
/* 70C86C 80238B5C 24030001 */  addiu     $v1, $zero, 1
/* 70C870 80238B60 90450006 */  lbu       $a1, 6($v0)
/* 70C874 80238B64 8C8700AC */  lw        $a3, 0xac($a0)
/* 70C878 80238B68 10A30010 */  beq       $a1, $v1, .L80238BAC
/* 70C87C 80238B6C 0000302D */   daddu    $a2, $zero, $zero
/* 70C880 80238B70 28A20002 */  slti      $v0, $a1, 2
/* 70C884 80238B74 10400005 */  beqz      $v0, .L80238B8C
/* 70C888 80238B78 24020002 */   addiu    $v0, $zero, 2
/* 70C88C 80238B7C 10A00007 */  beqz      $a1, .L80238B9C
/* 70C890 80238B80 28E20064 */   slti     $v0, $a3, 0x64
/* 70C894 80238B84 0808E2FE */  j         .L80238BF8
/* 70C898 80238B88 00000000 */   nop      
.L80238B8C:
/* 70C89C 80238B8C 10A2000F */  beq       $a1, $v0, .L80238BCC
/* 70C8A0 80238B90 28E20064 */   slti     $v0, $a3, 0x64
/* 70C8A4 80238B94 0808E2FE */  j         .L80238BF8
/* 70C8A8 80238B98 00000000 */   nop      
.L80238B9C:
/* 70C8AC 80238B9C 10400015 */  beqz      $v0, .L80238BF4
/* 70C8B0 80238BA0 24060002 */   addiu    $a2, $zero, 2
/* 70C8B4 80238BA4 0808E2FD */  j         .L80238BF4
/* 70C8B8 80238BA8 24060001 */   addiu    $a2, $zero, 1
.L80238BAC:
/* 70C8BC 80238BAC 28E20047 */  slti      $v0, $a3, 0x47
/* 70C8C0 80238BB0 14400010 */  bnez      $v0, .L80238BF4
/* 70C8C4 80238BB4 24060001 */   addiu    $a2, $zero, 1
/* 70C8C8 80238BB8 28E20064 */  slti      $v0, $a3, 0x64
/* 70C8CC 80238BBC 1040000E */  beqz      $v0, .L80238BF8
/* 70C8D0 80238BC0 24060003 */   addiu    $a2, $zero, 3
/* 70C8D4 80238BC4 0808E2FE */  j         .L80238BF8
/* 70C8D8 80238BC8 24060002 */   addiu    $a2, $zero, 2
.L80238BCC:
/* 70C8DC 80238BCC 28E20029 */  slti      $v0, $a3, 0x29
/* 70C8E0 80238BD0 14400008 */  bnez      $v0, .L80238BF4
/* 70C8E4 80238BD4 24060001 */   addiu    $a2, $zero, 1
/* 70C8E8 80238BD8 28E20047 */  slti      $v0, $a3, 0x47
/* 70C8EC 80238BDC 14400005 */  bnez      $v0, .L80238BF4
/* 70C8F0 80238BE0 24060002 */   addiu    $a2, $zero, 2
/* 70C8F4 80238BE4 28E20064 */  slti      $v0, $a3, 0x64
/* 70C8F8 80238BE8 10400003 */  beqz      $v0, .L80238BF8
/* 70C8FC 80238BEC 24060004 */   addiu    $a2, $zero, 4
/* 70C900 80238BF0 24060003 */  addiu     $a2, $zero, 3
.L80238BF4:
/* 70C904 80238BF4 28E20064 */  slti      $v0, $a3, 0x64
.L80238BF8:
/* 70C908 80238BF8 54400003 */  bnel      $v0, $zero, .L80238C08
/* 70C90C 80238BFC AC800084 */   sw       $zero, 0x84($a0)
/* 70C910 80238C00 24020001 */  addiu     $v0, $zero, 1
/* 70C914 80238C04 AC820084 */  sw        $v0, 0x84($a0)
.L80238C08:
/* 70C918 80238C08 AC8600C0 */  sw        $a2, 0xc0($a0)
/* 70C91C 80238C0C 03E00008 */  jr        $ra
/* 70C920 80238C10 24020002 */   addiu    $v0, $zero, 2
