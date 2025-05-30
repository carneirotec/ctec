import 'dart:io';

void main() {
  final extensoes = ['.s', '.S', '.c', '.cpp', '.h', '.hpp'];

  final substituicoes = {
    "define": "Defina",
    "include_next": "IncluaPróximo",
    "include": "Inclua",
    "ifdef": "SeDefinido",
    "ifndef": "SenãoDefinido",
    "elif": "SenãoSe",
    "endif": "FimSe",
    "defined": "Definido",
    "undef": "Indefinido",
    "error": "Erro",
    "warning": "Aviso",
    "line": "Linha",
    "pragma": "Diretiva",
    "__LINE__": "__LINHA__",
    "__FILE__": "__ARQUIVO__",
    "__DATE__": "__DATA__",
    "__TIME__": "__HORA__",
    "__FUNCTION__": "__FUNCTION__",
    "__VA_ARGS__": "__ARG_VARIÁDICOS__",
    "__COUNTER__": "__CONTADOR__",
    "int": "Inteiro",
    "void": "Vazio",
    "char": "Caractere",
    "if": "Se",
    "else": "Senão",
    "while": "Enquanto",
    "break": "Pare",
    "return": "Retorno",
    "for": "Para",
    "extern": "Externo",
    "static": "Estático",
    "unsigned": "SemSinal",
    "goto": "VáPara",
    "do": "Faça",
    "continue": "Continue",
    "switch": "Troque",
    "case": "Caso",
    "const": "Constante",
    "__const": "Constante",
    "__const__": "Constante",
    "volatile": "Volátil",
    "__volatile": "Volátil",
    "__volatile__": "Volátil",
    "long": "Longo",
    "register": "Registrador",
    "signed": "ComSinal",
    "__signed": "ComSinal",
    "__signed__": "ComSinal",
    "auto": "Automático",
    "inline": "EmLinha",
    "__inline": "EmLinha",
    "__inline__": "EmLinha",
    "restrict": "Restrito",
    "__restrict": "Restrito",
    "__restrict__": "Restrito",
    "__extension__": "__extension__",
    "generic": "Genérico",
    "_Generic": "Genérico",
    "float": "Real",
    "double": "Duplo",
    "_Bool": "Lógico",
    "short": "Curto",
    "struct": "Estrutura",
    "union": "União",
    "typedef": "Tipo",
    "default": "Padrão",
    "enum": "Enumeração",
    "sizeof": "TamanhoDe",
    "__attribute": "__attribute",
    "__attribute__": "__attribute__",
    "__alignof": "__alignof",
    "__alignof__": "__alignof__",
    "typeof": "TipoDe",
    "__typeof": "TipoDe",
    "__typeof__": "TipoDe",
    "__label__": "__label__",
    "asm": "Montador",
    "__asm": "Montador",
    "__asm__": "Montador",
  };

  final dir = Directory.current;

  dir.list(recursive: true).listen((entity) async {
    if (entity is File && extensoes.any(entity.path.endsWith)) {
      String content = await entity.readAsString();

      // substituições usando regex com quebra de palavra
      substituicoes.forEach((chave, valor) {
        final pattern = RegExp(r'\b' + RegExp.escape(chave) + r'\b');
        content = content.replaceAllMapped(pattern, (_) => valor);
      });

      await entity.writeAsString(content);
      print('Arquivo processado: ${entity.path}');
    }
  });
}
