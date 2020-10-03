.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel vi
/* 4613C 8006AD3C 32290008 */  andi      $t1, $s1, 8
/* 46140 8006AD40 11200008 */  beqz      $t1, ai
/* 46144 8006AD44 00000000 */   nop      
/* 46148 8006AD48 32310037 */  andi      $s1, $s1, 0x37
/* 4614C 8006AD4C 3C01A440 */  lui       $at, 0xa440
/* 46150 8006AD50 AC200010 */  sw        $zero, 0x10($at)
/* 46154 8006AD54 0C01ABDF */  jal       send_mesg
/* 46158 8006AD58 24040038 */   addiu    $a0, $zero, 0x38
/* 4615C 8006AD5C 12200034 */  beqz      $s1, NoMoreRcpInts
/* 46160 8006AD60 00000000 */   nop      
